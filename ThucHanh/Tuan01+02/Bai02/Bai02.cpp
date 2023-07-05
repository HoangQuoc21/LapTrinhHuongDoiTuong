#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main() {
    Stack stack;
    int choice = 0;
    string value;

    while (true) {
        system("cls");
        cout << "============================== MENU ============================\n";
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Size" << endl;
        cout << "0. Quit" << endl;
        cout << "============================== END =============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            if (stack.size() == 0) {
                cout << "Stack is empty." << endl;
            }
            else {
                cout << "Top value: " << stack.top() << endl;
            }
            break;
        case 4:
            cout << "Size: " << stack.size() << endl;
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        system("pause");
    }
    return 0;
}