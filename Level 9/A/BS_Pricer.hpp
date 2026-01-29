// BS_Pricer.hpp
#ifndef BS_Pricer_HPP
#define BS_Pricer_HPP

#include "Option.hpp"
#include "OptionData.hpp"
#include <vector>
using namespace std;

class BSPricer {
public:
    BSPricer() {}  // Empty constructor
    
    // Put-call parity
    double put_from_call(const Option& opt, double call_price, double b) const;
    double call_from_put(const Option& opt, double put_price, double b) const;
    
    // compute prices for range of S
    vector<double> price_S_range(const Option& base_option, double b, const vector<double>& S_values) const;
    
    //grid of (S × vol) combinations for calls
    vector<vector<double>> call_price_matrix(const vector<vector<OptionData>>& param_grid, double b) const;
    
    //grid of (S × vol) combinations for puts
    vector<vector<double>> put_price_matrix(const vector<vector<OptionData>>& param_grid, double b) const;
};

#endif
