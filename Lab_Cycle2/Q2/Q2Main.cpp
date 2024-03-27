#include <iostream>
#include "Q2.cpp" 

using namespace std;

template<typename T>
void menu(LinkedListStack<T>& stack) {
    char choice;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. PUSH" << endl;
        cout << "b. POP" << endl;
        cout << "c. IS EMPTY" << endl;
        cout << "d. IS FULL" << endl;
        cout << "e. Display" << endl;
        cout << "f. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                T value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 'b': {
                if (!stack.isEmpty()) {
                    cout << "Popped value: " << stack.pop() << endl;
                } else {
                    cerr << "Underflow: The stack is empty." << endl;
                }
                break;
            }
            case 'c': {
                cout << (stack.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            }
            case 'd': {
                cout << (stack.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            }
            case 'e': {
                stack.display();
                break;
            }
            case 'f': {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'f');
}

int main() {
    int maxsize;
    cout << "Enter maximum size of your stack: ";
    cin >> maxsize;

    char stackChoice;
    cout << "Choose the data type for the stack :  (i for int, d for double and c for char)" << endl;
    cin >> stackChoice;

    switch (stackChoice) {
        case 'i': {
            LinkedListStack<int> stackInt(maxsize);
            menu(stackInt);
            break;
        }
        case 'd': {
            LinkedListStack<double> stackDouble(maxsize);
            menu(stackDouble);
            break;
        }
        case 'c': {
            LinkedListStack<char> stackChar(maxsize);
            menu(stackChar);
            break;
        }
        default:
            cout << "Invalid choice. Exiting..." << endl;
    }

    return 0;
}
