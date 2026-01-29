#include <iostream>
#include "boost/shared_ptr.hpp" 
#include "Array.hpp"           
#include "Shape.hpp"           
#include "Circle.hpp"          
#include "Point.hpp"
using namespace std;

typedef boost::shared_ptr<suman::CAD::Shape> ShapePtr;
typedef suman::Containers::Array<ShapePtr> ShapeArray; 

int main() {
    // When execution leaves this scope {}, shapeArr object is destroyed
    {
        cout << "ShapeArray (size 3):"<<endl;
        ShapeArray shapeArr(3); 
        
        // points for Circle constructors
        suman::CAD::Point p1(1.0, 2.0);
        suman::CAD::Point p2(3.0, 4.0);

        cout << "Adding shapes to the array:"<<endl;
        
        // Circle wrapped in a boost::shared_ptr
        // The shared_ptr takes ownership of the dynamically allocated Circle object.
        shapeArr[0] = ShapePtr(new suman::CAD::Circle(p1, 2.0));
        cout << "Circle 1 at index 0"<<endl;
        
        // another Circle
        shapeArr[1] = ShapePtr(new suman::CAD::Circle(p2, 3.0));
        cout << "Added Circle 2 at index 1.\n";

        // leave the third slot null
        //it holds a default-constructed, empty ShapePtr)
        shapeArr[2] = ShapePtr(); 
        cout << "Slot at index 2 is null."<<endl;
        cout << "Printing Array Using Draw(): "<<endl;

        for (int i = 0; i < shapeArr.Size(); ++i) {
            ShapePtr& currentPtr = shapeArr[i];
            
            if (currentPtr) { 
                currentPtr->Draw(); 
                cout << "  " << currentPtr->ToString() << endl;
            } else {
                cout << "Index " << i << ": (NULL pointer)"<<endl;
            }
        }
        
        cout << "Destructors: "<<endl;
    } // 'shapeArr' destroyed here. 
      // This calls the destructors for the contained 'ShapePtr' objects, 
      // which then automatically 'delete' the Circle objects.

    return 0;
}