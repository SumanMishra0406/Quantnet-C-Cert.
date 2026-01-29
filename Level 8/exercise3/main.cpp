#include <iostream>
#include "ShapeVarient.hpp"
#include <string>

using namespace std;
using namespace suman::CAD;

// Helper function to print the shape using the visitor
void print_shape(const ShapeTypeVariant& variant, const string& label) {
    cout << label<<": "<<endl;
    
    // Create an instance of the PrintVisitor
    PrintVisitor printer; 

    boost::apply_visitor(printer, variant);
    cout << endl;
}


int main() {

    // Create the ShapeTypeVariant object
    ShapeTypeVariant my_shape_var = createShape(); 

    print_shape(my_shape_var, "Shape Created"); 

    // Testing boost::get and boost::bad_get exception
    cout << "Testing boost::get<Line>()"<<endl;
    try {
        // Attempt to get the Line type.
        const Line& extracted_line = boost::get<Line>(my_shape_var);
        // This line is only reached if the variant actually holds a Line
        cout << "Line details: " << extracted_line << endl;
    } catch (const boost::bad_get& e) {
        // This is the expected path if the user chose Point or Circle
        cout << "caught exception: " << e.what() << endl;
    }
    
    double move_x = 10.0;
    double move_y = -3.0;
    
    // Create an instance of the visitor
    MoveVisitor move_op(move_x, move_y);
    
    cout << "Applying MoveVisitor: " << endl;
    cout << "Moving shape by (" << move_x << ", " << move_y << ")\n";
    
    // Apply the visitor to modify the shape's coordinates
    boost::apply_visitor(move_op, my_shape_var);

    print_shape(my_shape_var, "Moved Shape Verification");

    return 0;
}