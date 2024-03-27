#include "Q6.cpp"

template<typename T>
void handleMenu() {
    LinkedListDEQUEUE<T> dequeue;
    char choice;
    T value;
    int position;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Insert elements to the Front of the queue" << endl;
        cout << "b. Insert elements to the Rear of the queue" << endl;
        cout << "c. Delete elements from the Front of the queue" << endl;
        cout << "d. Delete elements from the Rear of the queue" << endl;
        cout << "e. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                cout << "Enter value to insert at front: ";
                cin >> value;
                dequeue.insertFront(value);
                dequeue.display();
                break;
            }
            case 'b': {
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dequeue.insertRear(value);
                dequeue.display();
                break;
            }
            case 'c': {
                if (!dequeue.isEmpty()) {
                    cout << "Deleted value from front: " << dequeue.deleteFront() << endl;
                    dequeue.display();
                } else {
                    cerr << "Underflow: The queue is empty." << endl;
                }
                break;
            }
            case 'd': {
                if (!dequeue.isEmpty()) {
                    cout << "Deleted value from rear: " << dequeue.deleteRear() << endl;
                    dequeue.display();
                } else {
                    cerr << "Underflow: The queue is empty." << endl;
                }
                break;
            }  
            case 'e': {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'e');
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