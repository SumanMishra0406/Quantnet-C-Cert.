#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <boost/math/distributions/normal.hpp>
#include "OptionData.hpp"
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"

using namespace std;
// TestMC_Table.cpp
// 
// This file addresses parts (b) and (c) of the assignment:
//   - Part (b): Tests different values of NT and NSIM for Batches 1 & 2
//   - Part (c): Stress tests with Batch 4 data
// TestMC.cpp handles part (a) - basic MC simulation
namespace SDEDefinition
{
    OptionData* data;  // Pointer to option param (K, T, r, sig)
    
    double drift(double t, double X) { 
        return (data->r) * X; 
    }
    
    double diffusion(double t, double X){
        double betaCEV = 1.0;
        return data->sig * pow(X, betaCEV);
    }
}

double norm_cdf(double x) {
    boost::math::normal_distribution<> norm(0.0, 1.0);
    return boost::math::cdf(norm, x);
}

double BlackScholesPrice(double S, double K, double r, double sig, double T, int type)
{
    double b = r;
    double d1 = (log(S / K) + (b + 0.5 * sig * sig) * T) / (sig * sqrt(T));
    double d2 = d1 - sig * sqrt(T);

    if (type == 1)
        return S * exp((b - r) * T) * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2);
    else // Put
        return K * exp(-r * T) * norm_cdf(-d2) - S * exp((b - r) * T) * norm_cdf(-d1);
}

// Monte Carlo
double MonteCarloPrice(const OptionData& myOption, double S_0, long N, long NSIM)
{
    Range<double> range(0.0, myOption.T);
    vector<double> x = range.mesh(N);
    double k = myOption.T / double(N);
    double sqrk = sqrt(k);

    NormalGenerator* myNormal = new BoostNormal();
    using namespace SDEDefinition;
    SDEDefinition::data = const_cast<OptionData*>(&myOption);

    double sum = 0.0;

    //Main Monte Carlo
    for (long i = 0; i < NSIM; ++i)
    {
        double VOld = S_0, VNew = 0.0;
        
        // Evolve stock price through N time steps
        for (unsigned long j = 1; j < x.size(); ++j)
        {
            // Generate random
            double dW = myNormal->getNormal();
            
            VNew = VOld + k * drift(x[j - 1], VOld) + sqrk * diffusion(x[j - 1], VOld) * dW;
            VOld = VNew;
            
            if (VNew <= 0.0) { 
                VNew = 0.0; 
                break; 
            }
        }

        double payoff = myOption.myPayOffFunction(VNew);
        sum += payoff;
    }

    delete myNormal;
    double mean = sum / NSIM;
    return mean * exp(-myOption.r * myOption.T);
}

int main()
{
    struct BatchData { double T, K, sig, r, S, exactCall, exactPut; string name; };
    vector<BatchData> batches = {
        //{1.0, 100.0, 0.20, 0.05, 100.0, 0.0, 0.0, "FINAL EXAM"},
        {0.25, 65.0, 0.30, 0.08,  60.0, 2.13337, 5.84628, "Batch 1"},
        {1.0,  100.0, 0.20, 0.0, 100.0, 7.96557, 7.96557, "Batch 2"},
        {1.0,  10.0,  0.50, 0.12,  5.0, 0.204058, 4.07326, "Batch 3"},
        {30.0, 100.0, 0.30, 0.08, 100.0, 92.17570, 1.24750, "Batch 4 (Stress Test)"}
    };

    // Monte Carlo config
    vector<long> N_values_basic = {50, 100, 200};
    vector<long> NSIM_values_basic = {10000, 50000, 100000};

    vector<long> N_values_stress = {100, 500, 1000};
    vector<long> NSIM_values_stress = {50000, 100000, 500000};

    cout << fixed << setprecision(5);

    for (size_t i = 0; i < batches.size(); ++i)
    {
        auto b = batches[i];
        cout << "\n" << string(60, '=') << "\n";
        cout<<endl;
        cout << b.name << ": ";
        cout << "S=" << b.S << ", K=" << b.K<< ", r=" << b.r << ", sig=" << b.sig
             << ", T=" << b.T << "\n";
        cout << "Exact Call = " << b.exactCall << ", Exact Put = " << b.exactPut << "\n";
        cout << "\n" << string(60, '=') << "\n\n";

        OptionData myOption;
        myOption.K = b.K;
        myOption.T = b.T;
        myOption.r = b.r;
        myOption.sig = b.sig;
        myOption.type = -1; // -1 = Put option, +1 = Call option

        // Batch 4 (stress test) needs more steps and sim.
        auto N_values = (i == 3) ? N_values_stress : N_values_basic;
        auto NSIM_values = (i == 3) ? NSIM_values_stress : NSIM_values_basic;

        cout << string(60, '=') << "\n";
        cout << " N (steps) | NSim (paths) |  MC Price  | Abs Error\n";
        cout << string(60, '=') << "\n";

        for (size_t n = 0; n < N_values.size(); ++n)
        {
            long N = N_values[n];
            for (size_t s = 0; s < NSIM_values.size(); ++s)
            {
                long NSIM = NSIM_values[s];
                double mcPrice = MonteCarloPrice(myOption, b.S, N, NSIM);
                double absErr = fabs(mcPrice - b.exactPut);

                cout << setw(10) << N << " | "
                     << setw(12) << NSIM << " | "
                     << setw(10) << mcPrice << " | "
                     << setw(9) << absErr << "\n";
            }
        }
    }

    return 0;
}

/*
cd "/Users/sumanmishra/Desktop/CPP/quantnet/quantnet_hw/Level 9/C"
g++ -std=c++14 -I. -I/opt/homebrew/opt/boost/include TestMC_Table.cpp UtilitiesDJD/RNG/NormalGenerator.cpp -o TestMC_Table
./TestMC_Table
*/