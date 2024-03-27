#include "Q4.cpp"

template<typename T>
void handleMenu() {
    LinkedList<T> list;
    char choice;
    T value;
    int position;

    do {
        cout << "\n------- Menu -------" << endl;
        cout << "a. Insertion at Beginning" << endl;
        cout << "b. Insertion at End" << endl;
        cout << "c. Insertion at a specified position" << endl;
        cout << "d. Deletion from Beginning" << endl;
        cout << "e. Deletion from End" << endl;
        cout << "f. Deletion from a specified position" << endl;
        cout << "g. Display" << endl;
        cout << "h. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insert_at_beginning(value);
                break;
            case 'b':
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insert_at_end(value);
                break;
            case 'c':
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> position;
                list.insert_at_position(value, position);
                break;
            case 'd':
                list.delete_from_beginning();
                break;
            case 'e':
                list.delete_from_end();
                break;
            case 'f':
                cout << "Enter position to delete: ";
                cin >> position;
                list.delete_from_position(position);
                break;
            case 'g':
                cout << "Linked List: ";
                list.display();
                break;
            case 'h':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 'h');
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