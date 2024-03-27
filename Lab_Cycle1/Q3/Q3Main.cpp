#include "Q3.cpp"

template<typename T>
void handleMenu() {
    Array <T> myArray;
    char choice;
    T element;
    int shift;

    cout<<"Create an Array to access operations: "<<endl;

    do {
        cout << "Enter an element to add to the array: ";
        cin >> element;
        myArray.insert_at_end(element);

        cout << "Do you want to add another element? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');

    cout<<"The created array: "<<endl;
    myArray.display_array();

    do {
                cout << "\nMENU:\n";
                cout << "a. rotate Clockwise\n";
                cout << "b. rotate Anti-Clockwise\n";
                cout << "c. Print distinct elements of Array\n";
                cout << "d. Print a frequency table\n";
                cout << "e. Display the array\n";
                cout << "f. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
            case 'a':
                cout<<"Enter the magnitude you want to rotate: "<<endl;
                cin>>shift;
                myArray.rotateClockwise(shift);
                break;
            case 'b':
                cout<<"Enter the magnitude you want to rotate: "<<endl;
                cin>>shift;
                myArray.rotateAntiClockwise(shift);
                break;
            case 'c':
                cout<<"The distinct elements in array: "<<endl;
                myArray.printDistinctElements();
                break;
            case 'd':
                cout<<"Generated frequency table: "<<endl;
                myArray.generateFrequencyTable();
                break;
            case 'e':
                myArray.display_array();
                break;
            case 'f':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 'f');

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
