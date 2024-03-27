#include "Q7.cpp"

template<typename T>
void handleMenu() {
    TwoWayStack<T> stack;
    char choice;
    T value;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Push to Front" << endl;
        cout << "b. Push to Rear" << endl;
        cout << "c. Pop from Front" << endl;
        cout << "d. Pop from Rear" << endl;
        cout << "e. Display" << endl;
        cout << "f. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                cout << "Enter value to push to front: ";
                cin >> value;
                stack.pushFront(value);
                break;
            }
            case 'b': {
                cout << "Enter value to push to rear: ";
                cin >> value;
                stack.pushRear(value);
                break;
            }
            case 'c': {
                if (!stack.isEmpty()) {
                    cout << "Popped value from front: " << stack.popFront() << endl;
                } else {
                    cerr << "Underflow: The stack is empty." << endl;
                }
                break;
            }
            case 'd': {
                if (!stack.isEmpty()) {
                    cout << "Popped value from rear: " << stack.popRear() << endl;
                } else {
                    cerr << "Underflow: The stack is empty." << endl;
                }
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
    char type;
    cout << "Enter the data type of the Linked List (i for int, d for double, c for char): ";
    cin >> type;

    switch (type) {
        case 'i':
        handleMenu<int>();
            break;
        case 'd':
            handleMenu<double>();
            break;
        case 'c':
            handleMenu<char>();
            break;
        default:
            cout << "Invalid data type. Please try again." << endl;
    }

    return 0;
}