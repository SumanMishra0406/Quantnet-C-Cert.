#include "Stack.hpp" 
#include "StackException.hpp"
#include "ArrayException.hpp" 
#include <iostream>
#include <string>

using namespace suman::Containers;
using namespace std;
using std::string;

int main() {

    // The size is now defined at compile time using a value template argument.
    Stack<string, 5> stackA;
    Stack<string, 5> stackB(stackA); // Copy constructor (same size okay)
    // Can't do Stack<string, 10> stackC
    
    cout << "Created stackA (size 5) and stackB (size 5)." << endl;

    try {
        // Test pushing too many elements
        cout << "\nPushing 5 elements onto stackA (size 5)." << endl;
        stackA.Push("1"); stackA.Push("2"); stackA.Push("3"); stackA.Push("4"); stackA.Push("5");
        
        cout << "try pushing '6':" << endl;
        try {
            stackA.Push("6"); // Should fail and throw StackFullException
        } 
        // Catch the exception
        catch (const StackFullException& e) { 
            cout << "Caught StackFullException: " << e.GetMessage() << endl;
        }

        // Popping too many elements
        cout << "\nPopping all 5 elements from stackA:" << endl;
        cout << "Popped: " << stackA.Pop() << endl; // 5
        cout << "Popped: " << stackA.Pop() << endl; // 4
        cout << "Popped: " << stackA.Pop() << endl; // 3
        cout << "Popped: " << stackA.Pop() << endl; // 2
        cout << "Popped: " << stackA.Pop() << endl; // 1

        cout << "Pop from an empty stackA: " << endl;
        try {
            stackA.Pop(); // Should fail and throw StackEmptyException
        } 
        // Catch the exception
        catch (const StackEmptyException& e) { 
            cout << "Caught StackEmptyException: " << e.GetMessage() << endl;
        }

    } 
    catch (const StackException& e) {
        cout << "\nCaught unhandled Stack Exception: " << e.GetMessage() << endl;
    } 
    catch (...) {
        cout << "\nCaught unknown exception." << endl;
    }

    return 0;
}