#ifndef SMALLER_THAN_N_HPP
#define SMALLER_THAN_N_HPP

//Global Function

// Global func to check if a double is smaller than 30.0.
//hard code
bool IsSmallerThanThirty(double value) {
    return value < 30.0;
}


// Functor class that overloads the operator()
// to compare w/ val N during construction.
class IsSmallerThanN {
public:
    // Constructor to set the comparison value
    IsSmallerThanN(double n) : n_value(n) {}

    // overload function call operator
    bool operator()(double value) const {
        return value < n_value;
    }

private:
    double n_value;
};

#endif