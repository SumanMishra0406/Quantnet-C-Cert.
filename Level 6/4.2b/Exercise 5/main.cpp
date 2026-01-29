#include "Stack.hpp" 
#include "StackException.hpp"
#include "ArrayException.hpp"
#include <iostream>

using namespace suman::Containers;
using namespace std;

int main() {

    Stack<int> myStack(2);
    cout << "Stack<int> with size 2." << endl;

    try {
        myStack.Push(10); // m_current = 1
        myStack.Push(20); // m_current = 2
        cout << "\nStack is full." << endl;
        
        // Stack::Push should catch ArrayException and throw StackFullException.
        cout << "Push 30..." << endl;
        try {
            myStack.Push(30);
        } 
        catch (const StackFullException& e) { 
            cout << "Caught StackFullException: " << e.GetMessage() << endl;
        }

        // Popping too many elements
        cout << "\nPopping elements (LIFO order):" << endl;
        cout << "Pop: " << myStack.Pop() << endl; // Should be 20
        cout << "Pop: " << myStack.Pop() << endl; // Should be 10

        cout << "Pop from an empty stack: " << endl;
        try {
            myStack.Pop();
        } 
        catch (const StackEmptyException& e) { 
            cout << "Caught StackEmptyException: " << e.GetMessage() << endl;
        }

    } 
    catch (const StackException& e) {
        cout << "\nCaught unhandled Stack Exception: " << e.GetMessage() << endl;
    } 
    catch (const std::exception& e) {
        cout << "\nCaught generic standard exception: " << e.what() << endl;
    } 
    catch (...) {
        cout << "\nCaught unknown exception." << endl;
    }

    return 0;
}