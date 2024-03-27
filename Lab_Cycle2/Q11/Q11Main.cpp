#include "Q11.cpp"

int main() {
    FactorialCalculator calculator;
    int x;
    cout << "Enter the number  to find factorial : ";
    cin >> x;
    cout << calculator.factorialWithStack(x) << endl; 
    return 0;
}