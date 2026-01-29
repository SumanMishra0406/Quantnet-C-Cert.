// main.cpp
#include "Option.hpp"
#include "BS_Pricer.hpp"
#include "GreeksCalculator.hpp"
#include "Mesh.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct Batch {
    string name;
    OptionData data;
    double expected_call;
    double expected_put;
};

int main() {
    cout << fixed << setprecision(6);

    vector<Batch> batches = {
        // S K T r sig expected_call expected_put
        {"FINAL EXAM", {108, 120, 1.45, 0.045, 0.51}, 0.00, 0.00},
        {"Batch 1", {60, 65, 0.25, 0.08, 0.30}, 2.13337, 5.84628},
        {"Batch 2", {100, 100, 1.0, 0.00, 0.20}, 7.96557, 7.96557},
        {"Batch 3", {5, 10, 1.0, 0.12, 0.50}, 0.20406, 4.07326},
        {"Batch 4", {100, 100, 30.0, 0.08, 0.30}, 92.17570, 1.24750}
    };

    // Loop through each test batch and compare
    for (size_t i = 0; i < batches.size(); ++i) {
        const Batch& batch = batches[i];
        double b = 0; 

        // Create option object
        CallOption call(batch.data);
        PutOption put(batch.data);

        double C_calc = call.price(b);
        double P_calc = put.price(b);

        double C_err = fabs(C_calc - batch.expected_call);
        double P_err = fabs(P_calc - batch.expected_put);

        cout << "\n=== " << batch.name << " ===" << endl;
        cout << "C = " << C_calc << "{Expected: " << batch.expected_call 
            << ", Error: " << C_err << "}" << endl;

        cout << "P = " << P_calc 
             << "{Expected: " << batch.expected_put 
             << ", Error: " << P_err << "}" << endl;
    }
    // Results look good, errors are basically machine precision
    // Batch 2 makes sense: when r=0, call and put should be equal
    // Batch 4 is super high though - 30Y option with call ->> put (deep ITM)
    cout << "\n" << string(60, '-') << "\n";



    // Part 1.B: Put-call parity
    cout << "Part 1.B: Put-Call Parity Test";
    cout<<endl;

    OptionData batch4_data = {100, 100, 30.0, 0.08, 0.30}; //CHANGE
    double b_batch4 = batch4_data.r;

    CallOption call_batch4(batch4_data);
    PutOption put_batch4(batch4_data);

    double C_exact = call_batch4.price(b_batch4);
    double P_exact = put_batch4.price(b_batch4);

    // Use pricer for parity conversions
    BSPricer pricer;
    double call_from_put_val = pricer.call_from_put(put_batch4, P_exact, b_batch4);
    double put_from_call_val = pricer.put_from_call(call_batch4, C_exact, b_batch4);
    cout << "P (exact) = " << P_exact << endl;
    cout << "P (parity) = " << put_from_call_val << endl;
    cout << "Error = " << fabs(P_exact - put_from_call_val) << endl;

    cout << "C (exact) = " << C_exact << endl;
    cout << "C (parity) = " << call_from_put_val << endl;
    cout << "Error = " << fabs(C_exact - call_from_put_val) << endl;

    cout << "\n" << string(60, '-') << "\n\n";


    // Parity holds
    // Makes sense since we're using the exact same formulas



    // Part 1.C: Vector pricing
    cout << "Part 1.C: Vector of prices over S in [50,70] (h=2)\n";
    
    OptionData base = batches[0].data; // Use Batch x params
    double b_base = base.r;
    // Generate mesh S = [50, 52, 54, ..., 70] using template function
    auto S_grid = MeshArray<double>(50.0, 70.0, 2.0); //CHANGE
    
    // Create option objects and use pricer for batch processing
    CallOption temp_call(base);
    PutOption temp_put(base);
    
    BSPricer pricer_batch;
    auto calls_S = pricer_batch.price_S_range(temp_call, b_base, S_grid);
    auto puts_S  = pricer_batch.price_S_range(temp_put, b_base, S_grid);

    cout << "S\t\tCall\t\tPut\n";
    for (size_t i = 0; i < S_grid.size(); ++i) {
        cout << S_grid[i] << "      " << calls_S[i] << "        " << puts_S[i] << '\n';
        if (i >= 10) { 
            cout << "...\n";
            break; 
        }
    }

    cout << "\n" << string(60, '-') << "\n";
    cout << endl;


    
    // Part 1.D: Matrix pricing
    cout << "Part 1.D: Matrix of prices over vol x S\n";
    
    vector<double> vol_grid = {0.20, 0.30, 0.40};  // 3 volatility levels (CHANGE)
    
    // Build parameter matrix: each cell has different (S, sigma) combination
    vector<vector<OptionData>> param_matrix;
    
    for (size_t i = 0; i < vol_grid.size(); ++i) {
        vector<OptionData> row;
        for (size_t j = 0; j < S_grid.size(); ++j) {
            OptionData od = base; 
            od.S = S_grid[j]; // vary stock price across col
            od.sig = vol_grid[i]; // vary sigma across rows
            row.push_back(od);
        }
        param_matrix.push_back(row);
    }

    // Compute call and put prices for entire matrix at once
    BSPricer matrix_pricer;
    auto call_mat = matrix_pricer.call_price_matrix(param_matrix, b_base);
    auto put_mat  = matrix_pricer.put_price_matrix(param_matrix, b_base);

    cout << "S\\vol\t";
    for (size_t j = 0; j < S_grid.size() && j < 6; ++j){
        cout << S_grid[j] << "\t";
    }
    cout << endl;
    
    for (size_t i = 0; i < vol_grid.size(); ++i) {
        cout << "v=" << vol_grid[i] << "\t";
        for (size_t j = 0; j < call_mat[i].size() && j < 6; ++j) 
            cout << call_mat[i][j] << "\t";
        if (call_mat[i].size() > 6) cout << "...";
        cout << endl;
    }

    // Display full put matrix
    cout << "\nPut Matrix:\n";
    cout << "S\\vol\t";
    for (size_t j = 0; j < S_grid.size() && j < 6; ++j){
        cout << S_grid[j] << "\t";
    }
    cout << endl;
    
    for (size_t i = 0; i < vol_grid.size(); ++i) {
        cout << "v=" << vol_grid[i] << "\t";
        for (size_t j = 0; j < put_mat[i].size() && j < 6; ++j) 
            cout << put_mat[i][j] << "\t";
        if (put_mat[i].size() > 6) cout << "...";
        cout << endl;
    }

    cout << "\n" << string(60, '-') << "\n\n";




    // Part 2.A: Greeks
    cout << "Part 2.A: Exact Greeks for Futures Option\n";
    cout << "Data set: K=100, S=105, T=0.5, r=0.1, b=0, sig=0.36\n"; //change
    
    OptionData greeks_data = {108, 120, 1.45, 0.045, 0.51}; // S, K, T, r, sig //CHANGE
    double b_greeks = 0.0;
    
    CallOption call_greeks(greeks_data);
    PutOption put_greeks(greeks_data);
    
    double call_delta_exact = call_greeks.delta(b_greeks);
    double put_delta_exact = put_greeks.delta(b_greeks);
    double gamma_exact = call_greeks.gamma(b_greeks);  // same for calls/puts
    
    cout << "Delta_call = " << call_delta_exact 
         << " (Expected: 0.5946)\n";
    cout << "Delta_put = " << put_delta_exact 
         << " (Expected: -0.3566)\n";
    cout << "Gamma = " << gamma_exact << "\n";
    cout << "\n" << string(60, '-') << "\n";
    cout << endl;


    
    // PART 2.B: Delta sensitivity - how Delta changes with spot price
    // As S increases, Delta approaches 1 (ITM); as S decreases, Delta approaches 0 (OTM)
    cout << "Part 2.B: Call Delta for range of S values (80, 82, 84, ..., 120)\n";
    cout << "Using data from Part 2.A: K=100, T=0.5, r=0.1, b=0, sig=0.36\n\n";
    
    // Create mesh around strike (K=100) to see Delta behavior from OTM to ITM
    auto S_delta_grid = MeshArray<double>(80.0, 120.0, 2.0);  // step size h=2 (CHANGE)
    
    // Use GreeksCalculator to compute Delta for each S value
    GreeksCalculator greeks_calc;
    vector<double> delta_S = greeks_calc.delta_S_range(call_greeks, b_greeks, S_delta_grid); //call or put greeks
    
    // Print table
    cout << "S\t\tCall Delta\n";
    for (size_t i = 0; i < S_delta_grid.size(); i++) {
        if (i >= 15) {
            cout << "(showing first 15 of " << S_delta_grid.size() << " values)\n";
            break;
        }
        cout << S_delta_grid[i] << "        " << delta_S[i] << '\n';
    }

    cout << "\n" << string(60, '-') << "\n";
    cout << endl;

    // PART 2.C: 2D Greek matrix
    cout << "Part 2.C: Delta matrix over parameter grid\n";
    cout << "Using data from Part 2.A with varying S and volatility\n\n";
    
    // Create volatility grid (include original 0.36 from Part 2.A)
    vector<double> vol_delta_grid = {0.20, 0.30, 0.36, 0.4}; //CHANGE
    
    // Build option matrix for Delta computation
    vector<vector<OptionData>> delta_param_matrix;
    for (size_t i = 0; i < vol_delta_grid.size(); i++) {
        vector<OptionData> row;
        for (size_t j = 0; j < S_delta_grid.size(); j++) {
            OptionData option = greeks_data;  // base parameters
            option.S = S_delta_grid[j];       // vary S across columns
            option.sig = vol_delta_grid[i];   // vary sigma across rows
            row.push_back(option);
        }
        delta_param_matrix.push_back(row);
    }
    
    // Compute Delta for each (S, sigma) combination
    vector<vector<double>> delta_matrix = greeks_calc.delta_matrix(delta_param_matrix, b_greeks, true); //call true, put false
    
    // Print matrix (first 5 S columns)
    cout << "S\\vol\t";
    for (size_t j = 0; j < S_delta_grid.size() && j < 5; ++j) {
        cout << S_delta_grid[j] << "\t";
    }
    cout << endl;
    
    for (size_t i = 0; i < vol_delta_grid.size(); ++i) {
        cout << "v=" << vol_delta_grid[i] << "\t";
        for (size_t j = 0; j < delta_matrix[i].size() && j < 5; ++j) {
            cout << delta_matrix[i][j] << "\t";
        }
        if (delta_matrix[i].size() > 5) cout << "...";
        cout << endl;
    }

    cout << "\n" << string(60, '-') << "\n\n";

    // PART 2.D: Numerical Greeks using finite difference approximations
    cout << "Part 2.D: Divided differences for Delta and Gamma"<<endl;
    cout << "Comparing numerical approx. with exact values from Part 2.A\n";
    cout << "Using: K=100, S=105, T=0.5, r=0.1, b=0, sig=0.36\n\n";
    
    // Test with various h values to show convergence
    vector<double> h_vals = {1.0, 0.5, 0.1, 0.01, 0.001};
    
    cout << "h\t\tNum Delta\tDelta Error\tNum Gamma\tGamma Error\n";
    cout << string(60, '-') << '\n';
    
    for (size_t i = 0; i < h_vals.size(); ++i) {
        double h = h_vals[i];
        double num_delta = greeks_calc.numerical_delta(call_greeks, b_greeks, h); //call
        double delta_error = fabs(call_delta_exact - num_delta);
        
        double num_gamma = greeks_calc.numerical_gamma(call_greeks, b_greeks, h); //call
        double gamma_error = fabs(gamma_exact - num_gamma);
        
        cout << h << "\t\t" << num_delta << "\t" << delta_error 
             << "\t" << num_gamma << "\t" << gamma_error << endl;
    }
    
    cout << "\n Smaller h gives better approximation";
    cout<<endl;
    cout << "Exact Call Delta: " << call_delta_exact << ", Exact Gamma: " << gamma_exact << "\n";

    return 0;
}

/*
cd "/Users/sumanmishra/Desktop/CPP/quantnet/quantnet_hw/Level 9/A"
g++ -std=c++14 -I/opt/homebrew/opt/boost/include main.cpp Option.cpp BS_Pricer.cpp GreeksCalculator.cpp -o main

*/
