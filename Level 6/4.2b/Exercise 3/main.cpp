#include "PointArray.hpp"
#include "ArrayException.hpp"
#include <iostream>

using namespace suman::CAD;
using namespace suman::Containers;
using namespace std;

int main() {
    
    PointArray points(4);
    
    try {
        // Set points
        points[0] = Point(0.0, 0.0);
        points[1] = Point(1.0, 0.0);
        points[2] = Point(2.0, 3.0); 
        points[3] = Point(4.0, 5.0);

        cout << "P0: " << points[0] << endl;
        cout << "P1: " << points[1] << endl;
        cout << "P2: " << points[2] << endl;
        cout << "P3: " << points[3] << endl;

        //test length
        double total_l = points.Length();
        cout << "\nTotal Length of the path (P0->P1->P2->P3): " << total_l << endl;

    } catch (const ArrayException& e) {
        cout << "\nCaught Array Exception: " << e.GetMessage() << endl;
    } catch (const std::exception& e) {
        cout << "\nCaught Standard Exception: " << e.what() << endl;
    } catch (...) {
        cout << "\nCaught unknown exception." << endl;
    }

    return 0;
}