#include "Q4.cpp"

template<typename T>
void handleMenu() {
    int maxsize;
    cout << "Enter maximum size of Queue : " << endl;
    cin>>maxsize;
    LinkedListQueue<T> queue(maxsize);
    char choice;
    T value;
    int position;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Insert elements to the Rear of the queue" << endl;
        cout << "b. Delete elements from the Front of the queue" << endl;
        cout << "c. IS EMPTY" << endl;
        cout << "d. IS FULL" << endl;
        cout << "e. Display" << endl;
        cout << "f. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                T value;
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 'b': {
                if (!queue.isEmpty()) {
                    cout << "Dequeued value: " << queue.dequeue() << endl;
                } else {
                    cerr << "Underflow: The queue is empty." << endl;
                }
                break;
            }
            case 'c': {
                cout << (queue.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            }
            case 'd': {
                cout << (queue.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            }
            case 'e': {
                queue.display();
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