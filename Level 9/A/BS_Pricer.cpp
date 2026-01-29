// BS_Pricer.cpp
#include "BS_Pricer.hpp"
#include "Option.hpp"
#include <cmath>

using namespace std;
// Put Call Parity

double BSPricer::call_from_put(const Option& opt, double put_price, double b) const {
    double S = opt.S();
    double K = opt.K();
    double T = opt.T();
    double r = opt.r();
    
    return put_price + S * exp((b - r) * T) - K * exp(-r * T);
}

// Put Call Parity
double BSPricer::put_from_call(const Option& opt, double call_price, double b) const {
    double S = opt.S();
    double K = opt.K();
    double T = opt.T();
    double r = opt.r();
    
    return call_price - S * exp((b - r) * T) + K * exp(-r * T);
}


// Batch pricing methods

vector<double> BSPricer::price_S_range(const Option& base_option, double b,
                            const vector<double>& S_values) const {
    vector<double> prices;
    
    // get params from the base option
    OptionData data = base_option.getData();
    
    //Loop through each stock price in S_values
    for (size_t i = 0; i < S_values.size(); ++i) {
        data.S = S_values[i]; // modify only the stock price
        
        // temp option of correct type
        if (base_option.type() == "Call") {
            CallOption temp(data);
            prices.push_back(temp.price(b));
        } else {
            PutOption temp(data);
            prices.push_back(temp.price(b));
        }
        // temp object destroyed here
    }
    
    return prices;
}

vector<vector<double>> BSPricer::call_price_matrix(
    const vector<vector<OptionData>>& param_grid, double b) const {
    
    vector<vector<double>> price_matrix;
    
    // Loop through each row of the param grid
    for (size_t i = 0; i < param_grid.size(); ++i) {
        vector<double> price_row;

        // Loop through each col in current row
        for (size_t j = 0; j < param_grid[i].size(); ++j) {
            const OptionData& data = param_grid[i][j];
            
            CallOption call_opt(data);
            
            // Calculate price and add to current row
            price_row.push_back(call_opt.price(b));
        }

        price_matrix.push_back(price_row);
    }
    return price_matrix;
}

vector<vector<double>> BSPricer::put_price_matrix(
    const vector<vector<OptionData>>& param_grid, double b) const {
    
    vector<vector<double>> price_matrix;
    
    for (size_t i = 0; i < param_grid.size(); ++i) {
        vector<double> price_row;
        
        for (size_t j = 0; j < param_grid[i].size(); ++j) {
            const OptionData& data = param_grid[i][j];
            PutOption put_opt(data);
            price_row.push_back(put_opt.price(b));
        }
        price_matrix.push_back(price_row);
    }
    
    return price_matrix;
}

