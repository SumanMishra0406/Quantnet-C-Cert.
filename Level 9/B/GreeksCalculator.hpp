// GreeksCalculator.hpp

#ifndef GREEKSCALCULATOR_HPP
#define GREEKSCALCULATOR_HPP

#include "Option.hpp"
#include <vector>
using namespace std;

class GreeksCalculator {
public:
    GreeksCalculator() {}  // Empty constructor
    
    // calls option's built-in methods
    double delta(const Option& opt, double b) const;
    double gamma(const Option& opt, double b) const;
    
    // Batch Greek calculations
    // Compute Delta for range of S prices
    vector<double> delta_S_range(const Option& base_option, double b,
                                  const vector<double>& S_values) const;
    
    // Compute Delta matrix (S × vol grid)
    vector<vector<double>> delta_matrix(const vector<vector<OptionData>>& param_grid, 
                                    double b, bool is_call = true) const;
    
    // Numerical Greeks using finite differences
    double numerical_delta(const Option& opt, double b, double h = 0.01) const;
    double numerical_gamma(const Option& opt, double b, double h = 0.01) const;
};

#endif
