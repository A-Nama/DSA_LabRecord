#include "Q1.cpp"

template<typename T>
void handleMenu() {
    Array <T> myArray;
    char choice;
    T element;
    int pos, index;

    do {
        cout << "\nMENU:\n";
                 cout << "a. Insertion at Beginning\n";
                 cout << "b. Insertion at End\n";
                 cout << "c. Insertion at a specified pos\n";
                 cout << "d. Deletion from Beginning\n";
                 cout << "e. Deletion from End\n";
                 cout << "f. Deletion from a specified pos\n";
                 cout << "g. Find the index of a given element\n";
                 cout << "h. Display\n";
                 cout << "i. Exit\n";
                 cout << "Enter your choice: ";
                 cin >> choice;
        switch(choice){
                    case 'a':
                        cout << "Enter element to insert at beginning: ";
                        cin >> element;
                        myArray.insert_at_begin(element);
                        break;
                    case 'b':
                        cout << "Enter element to insert at end: ";
                        cin >> element;
                        myArray.insert_at_end(element);
                        break;
                    case 'c':
                        cout << "Enter element to insert: ";
                        cin >> element;
                        cout << "Enter pos to insert at: ";
                        cin >> pos;
                        myArray.insert_at_pos(element, pos);
                        break;
                     case 'd':
                        myArray.delete_at_begin();
                        break;
                     case 'e':
                        myArray.delete_at_end();
                        break;
                     case 'f':
                        cout << "Enter pos to delete from: ";
                        cin >> pos;
                        myArray.delete_at_pos(pos);
                        break;
                     case 'g':
                        cout << "Enter element to find index: ";
                        cin >> element;
                        index = myArray.findIndex(element);
                        if (index != -1)
                        cout << "Index of " << element << " is " << index << endl;
                        else
                        cout << "Element not found in the array.\n";
                        break;
                     case 'h':
                        myArray.display_array();
                        break;
                     case 'i':
                        cout << "Exiting program.\n";
                        break;
                     default:
                        cout << "Invalid choice. Please enter a valid option.\n";
                }
        } while (choice != 'i');

}

int main() {
    int data;
    cout << "Choose a Data type: " << endl;
    cout << "1. Integer,  2. float,  3. double,  4. char" << endl;
    cin >> data;

    switch (data) {
        case 1 :
            handleMenu<int>();
            break;
        case 2 :
            handleMenu<float>();
            break;
        case 3 :
            handleMenu<double>();
            break;
        case 4 :
            handleMenu<char>();
            break;
        default:
            cout << "Invalid data type. Please try again." << endl;
    }

    return 0;
}