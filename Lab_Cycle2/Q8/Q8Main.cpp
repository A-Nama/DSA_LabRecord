#include"Q8.cpp"

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}