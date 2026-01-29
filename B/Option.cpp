// Option.cpp
#include "Option.hpp"
#include <boost/math/distributions/normal.hpp>
#include <cmath>

using namespace std;

// Helper to compute d1 param
static double compute_d1(double S, double K, double T, double b, double sig) {
    return (log(S / K) + (b + 0.5 * sig * sig) * T) / (sig * sqrt(T));
}

// Helper for d2
static double compute_d2(double d1, double sig, double T) {
    return d1 - sig * sqrt(T);
}

static double N(double x) {
    boost::math::normal_distribution<> standard_normal(0.0, 1.0);
    return boost::math::cdf(standard_normal, x);
}

// Standard normal PDF (for Gamma)
static double n(double x) {
    return exp(-0.5 * x * x) / sqrt(2.0 * M_PI);
}

// Call Option

double CallOption::price(double b) const {
    double d1 = compute_d1(data.S, data.K, data.T, b, data.sig);
    double d2 = compute_d2(d1, data.sig, data.T);
    
    double term1 = data.S * exp((b - data.r) * data.T) * N(d1);
    double term2 = data.K * exp(-data.r * data.T) * N(d2);
    
    return term1 - term2;
}

/**
 * Call option Delta
 */
double CallOption::delta(double b) const {
    double d1 = compute_d1(data.S, data.K, data.T, b, data.sig);
    return exp((b - data.r) * data.T) * N(d1);
}

/**
 * Gamma (same for calls and puts)
 */
double CallOption::gamma(double b) const {
    double d1 = compute_d1(data.S, data.K, data.T, b, data.sig);
    double numerator = exp((b - data.r) * data.T) * n(d1);
    double denominator = data.S * data.sig * sqrt(data.T);
    return numerator / denominator;
}

// PutOption Implementation

double PutOption::price(double b) const {
    double d1 = compute_d1(data.S, data.K, data.T, b, data.sig);
    double d2 = compute_d2(d1, data.sig, data.T);
    
    double term1 = data.K * exp(-data.r * data.T) * N(-d2);
    double term2 = data.S * exp((b - data.r) * data.T) * N(-d1);
    
    return term1 - term2;
}
/**
 * Gamma
 */
double PutOption::gamma(double b) const {
    double d1 = compute_d1(data.S, data.K, data.T, b, data.sig);
    double numerator = exp((b - data.r) * data.T) * n(d1);
    double denominator = data.S * data.sig * sqrt(data.T);
    return numerator / denominator;
}

/**
 * Put option Delta
 * Always negative (put value decrease as S increases)
 */
double PutOption::delta(double b) const {
    double d1 = compute_d1(data.S, data.K, data.T, b, data.sig);
    return exp((b - data.r) * data.T) * (N(d1) - 1.0);
}

