// Option.hpp
// Base class for pricing and Greeks
// Derived classes for call/put specific behavior

#ifndef OPTION_HPP
#define OPTION_HPP

#include "OptionData.hpp"
#include <stdexcept>
#include <string>

/**
 * Abstract base class for European options
 * Defines interface for pricing and computing Greeks
 * Uses virtual functions to enable polymorphism
 */
class Option {
protected:
    OptionData data;  // S, K, T, r, sig
    
    // check params (all must be >0)
    void check() const {
        if (data.S <= 0) 
            throw std::invalid_argument("Stock price S must be positive");
        if (data.K <= 0) 
            throw std::invalid_argument("Strike price K must be positive");
        if (data.T <= 0) 
            throw std::invalid_argument("Time to maturity T must be positive");
        if (data.sig <= 0) 
            throw std::invalid_argument("Volatility sig must be positive");
    }

public:
    // Constructor
    Option(const OptionData& opt_data) : data(opt_data) {
        check();
    }
    
    // Virtual destructor for proper cleanup in derived classes
    virtual ~Option() = default;
    
    // Pure virtual functions - must be implemented by derived classes
    // These define the interface that all option types must provide
    
    /**
     * Compute option price using Black-Scholes formula
     * param b Cost of carry (b = r for non-dividend stock, b = r-q for dividend yield q)
     * return Option price
     */
    virtual double price(double b) const = 0;
    
    /**
     * Compute Delta (rate of change of option price with respect to spot)
     * param b Cost of carry
     * return Delta
     */
    virtual double delta(double b) const = 0;
    
    /**
     * Compute Gamma (rate of change of Delta with respect to spot)
     * Same formula for calls and puts
     * param b Cost of carry
     * return Gamma
     */
    virtual double gamma(double b) const = 0;
    
    /**
     * Get option type as string (for display/debugging)
     * return "Call" or "Put"
     */
    virtual std::string type() const = 0;
    
    // getters for option parameters
    double S() const { return data.S; }
    double K() const { return data.K; }
    double T() const { return data.T; }
    double r() const { return data.r; }
    double sig() const { return data.sig; }
    
    // Allow modification of spot price (for Greeks analysis)
    void setS(double new_S) { 
        if (new_S <= 0) 
            throw std::invalid_argument("Stock price must be >0");
        data.S = new_S; 
    }
    
    // Allow modification of volatility (for vol surface analysis)
    void setSig(double new_sig) { 
        if (new_sig <= 0) 
            throw std::invalid_argument("Volatility must be >0");
        data.sig = new_sig; 
    }
    
    // Get full data struct (for compatibility with existing code)
    const OptionData& getData() const { return data; }
};

/**
 * Call Option
 */
class CallOption : public Option {
public:
    CallOption(const OptionData& opt_data) : Option(opt_data) {}
    double price(double b) const override;
    double delta(double b) const override;
    double gamma(double b) const override;
    
    std::string type() const override { return "Call"; }
};

/**
 * Put Option
 */
class PutOption : public Option {
public:
    PutOption(const OptionData& opt_data) : Option(opt_data) {}
    
    // Override pure virtual function
    double price(double b) const override;
    double delta(double b) const override;
    double gamma(double b) const override;
    
    std::string type() const override { return "Put"; }
};

#endif // OPTION_HPP
