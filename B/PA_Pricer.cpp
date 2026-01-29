#include "PA_Pricer.hpp"
#include <cmath>
using namespace std;

// Helper y1 for call
double PA_Pricer::calc_y1(double sig, double r, double b) {
    double sig2 = sig * sig;
    return 0.5 - (b / sig2) + sqrt(pow((b / sig2 - 0.5), 2.0) + 2.0 * r / sig2);
}

// Helper y2 for put
double PA_Pricer::calc_y2(double sig, double r, double b) {
    double sig2 = sig * sig;
    return 0.5 - (b / sig2) - sqrt(pow((b / sig2 - 0.5), 2.0) + 2.0 * r / sig2);
}

// Perpetual American Call Option
double PA_Pricer::call_price(double K, double S, double sig, double r, double b) {
    double y1 = calc_y1(sig, r, b);

    // formula only works if y1 > 1
    if (y1 <= 1.0) return 0.0;

    return (K / (y1 - 1.0)) * pow(((y1 - 1.0) * S) / (y1 * K), y1);
}

// Perpetual American Put Option
double PA_Pricer::put_price(double K, double S, double sig, double r, double b) {
    double y2 = calc_y2(sig, r, b);

    // Formula (only valid if y2 < 0)
    if (y2 >= 0.0) return 0.0;

    return (K / (1.0 - y2)) * pow(((1.0 - y2) * S) / (-y2 * K), y2);
}

// vary S over a range
vector<double> PA_Pricer::call_price_S_range(double K, const vector<double>& S_values, double sig, double r, double b)
{
    vector<double> result;
    for (size_t i = 0; i < S_values.size(); i++) {
        result.push_back(call_price(K, S_values[i], sig, r, b));
    }
    return result;
}

vector<double> PA_Pricer::put_price_S_range(double K, const vector<double>& S_values, double sig, double r, double b)
{
    vector<double> result;
    for (size_t i = 0; i < S_values.size(); i++) {
        result.push_back(put_price(K, S_values[i], sig, r, b));
    }
    return result;
}

//  input matrix of S values
vector<vector<double>> PA_Pricer::call_price_matrix(double K, const vector<vector<double>>& S_matrix, double sig, double r, double b)
{
    vector<vector<double>> result;
    for (size_t i = 0; i < S_matrix.size(); i++) {
        vector<double> price_row;
        for (size_t j = 0; j < S_matrix[i].size(); j++) {
            price_row.push_back(call_price(K, S_matrix[i][j], sig, r, b));
        }
        result.push_back(price_row);
    }
    return result;
}

vector<vector<double>> PA_Pricer::put_price_matrix(double K, const vector<vector<double>>& S_matrix, double sig, double r, double b)
{
    vector<vector<double>> result;
    for (size_t i = 0; i < S_matrix.size(); i++) {
        vector<double> price_row;
        for (size_t j = 0; j < S_matrix[i].size(); j++) {
            price_row.push_back(put_price(K, S_matrix[i][j], sig, r, b));
        }
        result.push_back(price_row);
    }
    return result;
}
