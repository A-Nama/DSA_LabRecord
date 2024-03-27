#include "Q10.cpp"

int main() {
    BalancedBrackets bb;
    string expression;

    cout << "Enter an expression containing brackets: ";
    getline(cin, expression);

    if (bb.checkBalanced(expression)) {
        cout << "The expression is balanced." << endl;
    } 
    else {
        cout << "The expression is not balanced." << endl;
    }
    
    return 0;
}