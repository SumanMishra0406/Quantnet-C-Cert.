// GreeksCalculator.cpp
// Implementation of Greeks calculations

#include "GreeksCalculator.hpp"
#include <cmath>

using namespace std;

// Analytical Greeks - just call option's methods

double GreeksCalculator::delta(const Option& opt, double b) const {
    return opt.delta(b);
}

double GreeksCalculator::gamma(const Option& opt, double b) const {
    return opt.gamma(b);
}

// Batch Delta calculations

vector<double> GreeksCalculator::delta_S_range(const Option& base_option, double b,
                                                 const vector<double>& S_values) const {
    vector<double> deltas;
    OptionData data = base_option.getData();
    
    for (size_t i = 0; i < S_values.size(); ++i) {
        data.S = S_values[i];
        
        if (base_option.type() == "Call") {
            CallOption temp_option(data);
            deltas.push_back(temp_option.delta(b));
        } else {
            PutOption temp_option(data);
            deltas.push_back(temp_option.delta(b));
        }
    }
    
    return deltas;
}

vector<vector<double>> GreeksCalculator::delta_matrix(
    const vector<vector<OptionData>>& param_grid, double b, bool is_call) const {
    
    vector<vector<double>> delta_matrix;
    
    for (size_t i = 0; i < param_grid.size(); ++i) {
        vector<double> delta_row;
        
        for (size_t j = 0; j < param_grid[i].size(); ++j) {
            const OptionData& data = param_grid[i][j];
            
            if (is_call) {
                CallOption call_opt(data);
                delta_row.push_back(call_opt.delta(b));
            } else {
                PutOption put_opt(data);
                delta_row.push_back(put_opt.delta(b));
            }
        }
        
        delta_matrix.push_back(delta_row);
    }
    
    return delta_matrix;
}

//  Greeks using finite differences

double GreeksCalculator::numerical_delta(const Option& opt, double b, double h) const {
    double S_original = opt.S();
    OptionData data = opt.getData();
    
    // V(S + h)
    data.S = S_original + h;
    double price_up;
    if (opt.type() == "Call") {
        CallOption opt_up(data);
        price_up = opt_up.price(b);
    } else {
        PutOption opt_up(data);
        price_up = opt_up.price(b);
    }
    
    // V(S - h)
    data.S = S_original - h;
    double price_down;
    if (opt.type() == "Call") {
        CallOption opt_down(data);
        price_down = opt_down.price(b);
    } else {
        PutOption opt_down(data);
        price_down = opt_down.price(b);
    }
    
    // Centered difference: [V(S+h) - V(S-h)] / (2h)
    return (price_up - price_down) / (2.0 * h);
}

double GreeksCalculator::numerical_gamma(const Option& opt, double b, double h) const {
    double S_original = opt.S();
    OptionData data = opt.getData();
    
    // V(S)
    double price_mid = opt.price(b);
    
    // V(S + h)
    data.S = S_original + h;
    double price_up;
    if (opt.type() == "Call") {
        CallOption opt_up(data);
        price_up = opt_up.price(b);
    } else {
        PutOption opt_up(data);
        price_up = opt_up.price(b);
    }
    
    // V(S - h)
    data.S = S_original - h;
    double price_down;
    if (opt.type() == "Call") {
        CallOption opt_down(data);
        price_down = opt_down.price(b);
    } else {
        PutOption opt_down(data);
        price_down = opt_down.price(b);
    }
    
    // Second derivative
    return (price_up - 2.0 * price_mid + price_down) / (h * h);
}
