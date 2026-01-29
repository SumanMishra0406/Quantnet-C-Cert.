// OptionData.hpp
// data structure to hold European option parameters
// struct because we just need a data container with public access
#ifndef OPTIONDATA_HPP
#define OPTIONDATA_HPP

struct OptionData {
    double S;   // underlying asset price
    double K;   // Strike 
    double T;   // Time to maturity
    double r;   // Risk-free  rate
    double sig; // Volatility
};

#endif
