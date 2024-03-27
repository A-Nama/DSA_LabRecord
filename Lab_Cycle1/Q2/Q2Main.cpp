#include "Q2.cpp"

template<typename T>
void handleMenu() {
    Array <T> myArray;
    char choice;
    T element;
    int lower,upper;
    int pos1,pos2;

    cout<<"Create an Array to access operations: "<<endl;
    do {
        cout << "Enter an element to add to the array: ";
        cin >> element;
        myArray.insert_at_end(element);

        cout << "Do you want to add another element? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    do {
                cout << "\nMENU:\n";
                cout << "a. Quicksort\n";
                cout << "b. Bubblesort\n";
                cout << "c. Insertionsort\n";
                cout << "d. Mergesort\n";
                cout << "e. Selection sort\n";
                cout << "f. Linear search\n";
                cout << "g. Binary search\n";
                cout << "h. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 'a':
                        cout<<"Enter lowerbound index: "<<endl;
                        cin>>lower;
                        cout<<"Enter upperbound index: "<<endl;
                        cin>>upper;
                        cout<<"Sorted Array: "<<endl;
                        myArray.quicksort(lower,upper);
                        myArray.display_array();
                        break;
                    case 'b':
                        cout<<"Sorted Array: "<<endl;
                        myArray.bubble_sort();
                        myArray.display_array();

                        break;
                    case 'c':
                        cout<<"Sorted Array: "<<endl;
                        myArray.insertion_sort();
                        myArray.display_array();
                        break;
                    case 'd':
                        cout<<"Enter lowerbound index: "<<endl;
                        cin>>lower;
                        cout<<"Enter upperbound index: "<<endl;
                        cin>>upper;
                        cout<<"Sorted Array: "<<endl;
                        myArray.mergesort(lower,upper);
                        myArray.display_array();
                        break;
                    case 'e':
                        cout<<"Sorted Array: "<<endl;
                        myArray.selection_sort();
                        myArray.display_array();
                        break;
                    case 'f':
                        cout << "Enter the element you want to search ";
                        cin >> element;
                        pos1 = myArray.linearsearch(element);
                        cout<<"Element at : "<<pos1<<endl;
                        break;
                    case 'g':
                        cout << "Enter the element you want to search ";
                        cin >> element;
                        pos2 = myArray.binarysearch(element);
                        cout<<"Element at : "<<pos2<<endl;
                        break;
                    case 'h':
                       cout << "Exiting program.\n";
                       break;
                    default:
                       cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 'h');

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