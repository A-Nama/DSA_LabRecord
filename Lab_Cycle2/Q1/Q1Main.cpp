#include "Q1.cpp"

template<typename T>
void menu(Stack<T>& stack) {
    char choice;
    T element;

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
            case 'a':
                cout << "Push an element to stack."<<endl;
                cin >> element;
                stack.push(element);
                break;
            case 'b':
                cout << "Popped value "<<endl;
                stack.pop();
                break;
            case 'c':
                cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 'd':
                cout << (stack.isFull() ? "Stack is full" : "Stack is not full") << endl;
                break;
            case 'e':
                cout <<"Display stack"<<endl;
                stack.display_stack();
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
    int size;
    cout<<"Enter max size of stack : \n";
    cin>>size;
    Stack<int> stackInt(size);
    Stack<double> stackDouble(size);
    Stack<char> stackChar(size);

    char data;
    cout << "Choose the data type for the stack :  (i for int, d for double and c for char)" << endl;
    cin >> data;

    switch (data) {
        case 'i' :
            menu(stackInt);
            break;
        case 'd' :
            menu(stackDouble);
            break;
        case 'c' :
            menu(stackChar);
            break;
        default:
            cout << "Invalid choice. Exiting..." << endl;
    }

    return 0;
}
