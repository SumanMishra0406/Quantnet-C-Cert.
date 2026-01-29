#include "Stack.hpp" 
#include "ArrayException.hpp"

using namespace suman::Containers;
using namespace std;

int main() {
    Stack<int> myStack(3);
    cout << "Stack<int> with size 3" << endl;

    try {
        //Push elements
        myStack.Push(10); // m_current = 1
        myStack.Push(20); // m_current = 2
        myStack.Push(30); // m_current = 3 (Full)
        cout << "Pushed 10, 20, 30." << endl;
        
        // Push when Stack is full ---
        // Stack::Push delegates to Array::operator[], which throws OutOfBoundsException 
        // when m_current == size.
        cout << "\nPush 40 when Stack is full" << endl;
        try {
            myStack.Push(40);
        } 
        catch (const ArrayException& e) { 
            cout << "Caught ArrayException (Stack Full): " << e.GetMessage() << endl;
        }

        // Pop elements - lifo
        cout << "\nPop elements:" << endl;
        cout << "   Pop: " << myStack.Pop() << endl; // 30
        cout << "   Pop: " << myStack.Pop() << endl; // Should be 20
        cout << "   Pop: " << myStack.Pop() << endl; // Should be 10

        // Test Pop when Stack is empty
        cout << "\nPop from an empty stack" << endl;
        try {
            myStack.Pop();
        } 
        catch (const ArrayException& e) { 
            cout << "Caught ArrayException (Stack Empty): " << e.GetMessage() << endl;
        }

    } 
    // General error capture
    catch (const std::exception& e) {
        cout << "A standard exception occurred: " << e.what() << endl;
    } catch (...) {
        cout << "An unknown exception occurred." << endl;
    }

    return 0;
}