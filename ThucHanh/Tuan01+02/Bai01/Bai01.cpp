#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;


int main() {
    int capacity;
    int currentSize;
    int element;
    int top;
    cout << "Enter capacity of stack: ";
    cin >> capacity;
    Stack stack(capacity);
    string choice;
    
    while (1) {
        system("cls");

        currentSize = stack.getCurrentSize();
        cout << "Capacity: " << capacity << endl;
        if (currentSize == -1)
            cout << "Stack is empty.\n";
        else {
            cout << "Current size: " << currentSize + 1 << endl;
        }
        
        cout << "1. push an element to stack.\n";
        cout << "2. pop an element from stack.\n";
        cout << "0. exit program.\n";
        cout << "--------------------------------\n";
        cout << "your choice: ";
        fflush(stdin);
        cin >> choice;
        cout << "--------------------------------\n";
        if (choice == "1") {
            if (currentSize + 1 == capacity) {
                cout << "Stack is full.\n";
            }
            else {
                cout << "enter the pushing element: ";
                cin >> element;
                stack.push(element);
                cout << "element pushed to stack.\n";
            }
        }
        else if (choice == "2") {
            if (currentSize == -1)
                cout << "stack is empty.\n";
            else {
                int top = stack.pop();
                cout << "the popped element: " << top << endl;
            }
        }
        else if (choice == "0") {
            cout << "exit program successfully.\n";
            break;
        }
        else
            cout << "invalid choice.\n";

        system("pause");
    }
    return 0;
}