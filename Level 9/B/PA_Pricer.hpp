#ifndef PA_Pricer_HPP
#define PA_Pricer_HPP

#include <cmath>
#include <vector>

class PA_Pricer{
public:
    // Call
    static double call_price(double K, double S, double sig, double r, double b);

    //Put
    static double put_price(double K, double S, double sig, double r, double b);
    
    //vary S over a range, keep other params fixed
    static std::vector<double> call_price_S_range(double K, const std::vector<double>& S_values, double sig, double r, double b);
    static std::vector<double> put_price_S_range(double K, const std::vector<double>& S_values, double sig, double r, double b);
    
    // input matrix of S values, keep other params fixed
    static std::vector<std::vector<double>> call_price_matrix(double K, const std::vector<std::vector<double>>& S_matrix, double sig, double r, double b);
    static std::vector<std::vector<double>> put_price_matrix(double K, const std::vector<std::vector<double>>& S_matrix, double sig, double r, double b);
    
private:
    // Helper function to calculate y1
    static double calc_y1(double sig, double r, double b);

    // Helper function to calculate y2
    static double calc_y2(double sig, double r, double b);
};

#endif // PA_Pricer_HPP