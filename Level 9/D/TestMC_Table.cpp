#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>
#include "OptionData.hpp"
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"

using namespace std;

// Stdev and se fns
double computeSD(const vector<double>& payoffs, double r, double T)
{
    size_t M = payoffs.size();
    if (M <= 1) return 0.0;

    double sum = accumulate(payoffs.begin(), payoffs.end(), 0.0); //accumulate from std library
    double sumsq = 0.0;
    for (double x : payoffs){
        sumsq += x * x;
    }
    double variance = (sumsq - (sum * sum) / M) / (M - 1);
    return sqrt(variance) * exp(-r * T);
}

double computeSE(double SD, size_t M)
{
    if (M == 0) return 0.0;
    return SD / sqrt(static_cast<double>(M)); //static_cast to ensure double division
}

namespace SDEDefinition
{
    OptionData* data;
    double drift(double t, double X) { return data->r * X; }
    double diffusion(double t, double X) { return data->sig * pow(X, 1.0); }
}

// Monte Carlo  with SD/SE
double MonteCarloPriceSDSE(const OptionData& myOption, double S_0, long N, long NSIM, double& SD, double& SE)
{
    Range<double> range(0.0, myOption.T);
    vector<double> x = range.mesh(N);
    double k = myOption.T / double(N);
    double sqrk = sqrt(k);

    NormalGenerator* myNormal = new BoostNormal();
    using namespace SDEDefinition;
    SDEDefinition::data = const_cast<OptionData*>(&myOption);

    vector<double> payoffs;
    payoffs.reserve(NSIM);

    for (long i = 0; i < NSIM; ++i)
    {
        double VOld = S_0, VNew = 0.0;
        for (unsigned long j = 1; j < x.size(); ++j)
        {
            double dW = myNormal->getNormal();
            VNew = VOld + k * drift(x[j - 1], VOld)
                          + sqrk * diffusion(x[j - 1], VOld) * dW;
            VOld = VNew;
            if (VNew <= 0.0) { VNew = 0.0; break; } // barrier
        }

        payoffs.push_back(myOption.myPayOffFunction(VNew));
    }

    delete myNormal;

    SD = computeSD(payoffs, myOption.r, myOption.T);
    SE = computeSE(SD, payoffs.size());

    double mean = accumulate(payoffs.begin(), payoffs.end(), 0.0) / payoffs.size();
    return mean * exp(-myOption.r * myOption.T);
}

int main()
{

    /*
    Find the Price, SD, and SE of the below Call using MC:
    Spot:  150
    Strike:  155
    r = 4%
    T = 1.28
    sig = .27
    b = r

    
    
    */
    struct BatchData { double T, K, sig, r, S, exactCall, exactPut; string name; };
    vector<BatchData> batches = {
        {1.28, 155, 0.27, 0.04, 150, 0.0, 0.0, "FINAL EXAM"},
        {0.25, 65.0, 0.30, 0.08,  60.0, 2.13337, 5.84628, "Batch 1"},
        {1.0,  100.0, 0.20, 0.0, 100.0, 7.96557, 7.96557, "Batch 2"},
        {1.0,  10.0,  0.50, 0.12,  5.0, 0.204058, 4.07326, "Batch 3"},
        {30.0, 100.0, 0.30, 0.08, 100.0, 92.17570, 1.24750, "Batch 4 (Stress Test)"}
    };

    vector<long> N_values_basic = {75};
    vector<long> NSIM_values_basic = {1000000};
    vector<long> N_values_stress = {100, 500, 1000};
    vector<long> NSIM_values_stress = {50000, 100000, 500000};

    cout << fixed << setprecision(5);

    for (size_t i = 0; i < batches.size(); ++i)
    {
        auto b = batches[i];
        cout << "\n" << string(60, '-') << "\n\n";
        cout << b.name << ": S=" << b.S << ", K=" << b.K
             << ", r=" << b.r << ", sig=" << b.sig
             << ", T=" << b.T << "\n";
        cout << "Exact Call = " << b.exactCall << ", Exact Put = " << b.exactPut << "\n";
        cout << "\n" << string(60, '-') << "\n\n";

        OptionData myOption;
        myOption.K = b.K;
        myOption.T = b.T;
        myOption.r = b.r;
        myOption.sig = b.sig;
        myOption.type = 1; // 1 == call, -1 == put

        auto N_values = (i == 3) ? N_values_stress : N_values_basic;
        auto NSIM_values = (i == 3) ? NSIM_values_stress : NSIM_values_basic;

    cout << "---------------------------------------------------------------\n";
    cout << " N (steps) | NSim (paths) | MC Price | SD | SE | Abs Error\n";
    cout << "---------------------------------------------------------------\n";

        for (size_t n = 0; n < N_values.size(); ++n)
        {
            long N = N_values[n];
            for (size_t s = 0; s < NSIM_values.size(); ++s)
            {
                long NSIM = NSIM_values[s];
                double SD, SE;
                double mcPrice = MonteCarloPriceSDSE(myOption, b.S, N, NSIM, SD, SE);
                double absErr = fabs(mcPrice - b.exactPut);

             cout << N << " | "
                 << NSIM << " | "
                 << mcPrice << " | "
                 << SD << " | "
                 << SE << " | "
                 << absErr << "\n";
            }
        }
    }

    return 0;
}

/*
cd "/Users/sumanmishra/Desktop/CPP/quantnet/quantnet_hw/Level 9/D"
g++ -std=c++14 -I. -I/opt/homebrew/opt/boost/include TestMC_Table.cpp UtilitiesDJD/RNG/NormalGenerator.cpp -o TestMC_Table
./TestMC_Table
*/