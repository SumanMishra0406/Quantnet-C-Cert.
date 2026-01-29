#include "BS_Pricer.hpp"
#include "Option.hpp"
#include "PA_Pricer.hpp"
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
    
    // Part B: single option test
    cout << "Part 3.B: Perpetual American Option Pricing";
    cout<<endl;
    cout << "K=100, S=110, sig=0.1, r=0.1, b=0.02"; cout<<endl;
    cout<<endl;

    double K_pa = 100.0;
    double S_pa = 110.0;
    double sig_pa = 0.1;
    double r_pa = 0.1;
    double b_pa = 0.02;

    double C_pa_calc = PA_Pricer::call_price(K_pa, S_pa, sig_pa, r_pa, b_pa);
    double P_pa_calc = PA_Pricer::put_price(K_pa, S_pa, sig_pa, r_pa, b_pa);

    double C_pa_expected = 18.5035;
    double P_pa_expected = 3.03106;

    double C_pa_err = fabs(C_pa_calc - C_pa_expected);
    double P_pa_err = fabs(P_pa_calc - P_pa_expected);
    
    cout << "C = " << C_pa_calc << " (expected: " << C_pa_expected << ", error: " << C_pa_err << ")" << endl;

    cout << "P = " << P_pa_calc << " (expected: " << P_pa_expected << ", error: " << P_pa_err << ")" << endl;

    cout << "\n" << string(60, '-') << "\n";
    cout << endl;
    
    //---------------------------------------------------

    // Part C: price vector over S
    cout << "Part 3.C: Perpetual American prices over S range\n";
    cout << "S from 10 to 50, h=4"; cout<<endl;
    cout << "K=100, sig=0.1, r=0.1, b=0.02"; cout<<endl;
    
    vector<double> S_mesh = MeshArray<double>(10.0, 50.0, 4.0);
    
    //  perpetual American option prices for each S
    vector<double> pa_calls = PA_Pricer::call_price_S_range(K_pa, S_mesh, sig_pa, r_pa, b_pa);
    vector<double> pa_puts = PA_Pricer::put_price_S_range(K_pa, S_mesh, sig_pa, r_pa, b_pa);
    
    cout << "S\t\tCall\t\t\tPut\n";
    for (size_t i = 0; i < S_mesh.size(); i++) {
        cout << S_mesh[i] << "      " << pa_calls[i] << "       " << pa_puts[i] << endl;
    }
    
    cout << "\n" << string(60, '-') << "\n\n";
    //---------------------------------------------------
    // Part D: matrix pricing
    cout << "Part 3.D: Matrix prices";
    cout<<endl;
    cout << "Rows = volatility, Columns = S\n";
    cout << "K=100, r=0.1, b=0.02\n\n";
    
    // volatility grid (rows) and S grid (columns)
    vector<double> vol_grid;
    vol_grid.push_back(0.1);
    vol_grid.push_back(0.2);
    vol_grid.push_back(0.3);
    
    auto S_grid_matrix = MeshArray<double>(80.0, 120.0, 10.0);
    
    // build matrix
    vector<vector<double>> S_matrix;
    for (size_t i = 0; i < vol_grid.size(); i++) {
        vector<double> row;
        for (size_t j = 0; j < S_grid_matrix.size(); j++) {
            row.push_back(S_grid_matrix[j]);
        }
        S_matrix.push_back(row);
    }
    
    // call prices
    cout << "Call prices:\n";
    cout << "S\\vol\t";
    for (size_t j = 0; j < S_grid_matrix.size(); j++) {
        cout << S_grid_matrix[j] << "   ";
    }
    cout << endl;
    
    for (size_t i = 0; i < vol_grid.size(); i++) {
        double vol = vol_grid[i];
        vector<vector<double>> call_mat = PA_Pricer::call_price_matrix(K_pa, S_matrix, vol, r_pa, b_pa);
        
        cout << "v=" << vol << "    ";
        for (size_t j = 0; j < call_mat[i].size(); j++) {
            cout << call_mat[i][j] << "\t";
        }
        cout << endl;
    }
    
    // put prices
    cout << "\nPut prices: ";
    cout << endl;
    cout << "S\\vol\t";
    for (size_t j = 0; j < S_grid_matrix.size(); j++) {
        cout << S_grid_matrix[j] << "   ";
    }
    cout << endl;
    
    for (size_t i = 0; i < vol_grid.size(); i++) {
        double vol = vol_grid[i];
        vector<vector<double>> put_mat = PA_Pricer::put_price_matrix(K_pa, S_matrix, vol, r_pa, b_pa);
        
        cout << "v=" << vol << "    ";
        for (size_t j = 0; j < put_mat[i].size(); j++) {
            cout << put_mat[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << endl;
    cout << string(60, '-') << "\n";
    return 0;
}

/*
cd "/Users/sumanmishra/Desktop/CPP/quantnet/quantnet_hw/Level 9/B"
g++ -std=c++14 -I/opt/homebrew/opt/boost/include main.cpp Option.cpp BS_Pricer.cpp GreeksCalculator.cpp PA_Pricer.cpp -o main

*/
