#include "Q6.cpp"

int main() {
    cout << "Enter details for Polynomial 1:" << endl;
    Polynomial poly1 = poly1.getPolynomial();

    cout << "Enter details for Polynomial 2:" << endl;
    Polynomial poly2 = poly2.getPolynomial();

    cout << endl << "Polynomial 1: ";
    poly1.display();
    cout << endl;

    cout << "Polynomial 2: ";
    poly2.display();
    cout << endl;

    Polynomial addition = poly1.add(poly2);
    cout << "Addition: ";
    addition.display();
    cout << endl;

    Polynomial multiplication = poly1.multiply(poly2);
    cout << "Multiplication: ";
    multiplication.display();
    cout << endl;

    return 0;
}
