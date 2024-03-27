#include"Q3.cpp"

template<typename T>
void handleMenu(Queue<T> queue) {
    char choice;
    T value;
    int position;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Insert elements to the Rear of the queue" << endl;
        cout << "b. Delete elements from the Front of the queue" << endl;
        cout << "c. Is Empty" << endl;
        cout << "d. Is Full" << endl;
        cout << "e. Display" << endl;
        cout << "f. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 'b': {
                if (!queue.isEmpty()) {
                    cout << "Dequeued value: " << queue.dequeue() << endl;
                } else {
                    cout << "Queue Underflow." << endl;
                }
                break;
            }
            case 'c': {
                cout << (queue.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            }
            case 'd': {
                cout << (queue.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
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
    int capacity;
    cout << "Enter the capacity of the Queue: ";
    cin >> capacity;

    Queue<int> queueInt(capacity);
    Queue<double> queueDouble(capacity);
    Queue<char> queueChar(capacity);
    char data;
    cout << "Choose the data type for the Queue :  (i for int, d for double and c for char)" << endl;
    cin >> data;

    switch (data) {
        case 'i' :
            handleMenu(queueInt);
            break;
        case 'd' :
            handleMenu(queueDouble);
            break;
        case 'c' :
            handleMenu(queueChar);
            break;
        default:
            cout << "Invalid data type. Please try again." << endl;
    }

    return 0;
}