#include <ctime>
#include <map>
#include <iostream>
#include <boost/random.hpp>
#include <boost/random/detail/const_mod.hpp>

using namespace std;

int main() {
    // Throwing dice.
    // Mersenne Twister.
    boost::random::mt19937 myRng;

    // Set the seed.
    myRng.seed(static_cast<boost::uint32_t> (time(0)));

    // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1,6);


    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome; // Current outcome


    cout << "How many trials? "; 
    int n;
    cin>>n;

    //initializing
    for(int i=1; i<=6; ++i){
        statistics[i]= 0;
    }

    //dice
    for(int i=0; i<n; ++i){
        outcome = six(myRng); //generate rand. num. from [1,6]
        statistics[outcome]++;
    }
    cout << "\n";

    for (int i = 1; i <= 6; ++i){
        cout << "Trial " << i << " has " << 100.0 * double(statistics[i]) / double(n) << "% outcomes" << endl;
    }

    return 0;


}