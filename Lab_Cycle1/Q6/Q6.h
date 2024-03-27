#include <iostream>
using namespace std;

struct Term {
    int coefficient;
    int exponent;
    Term* next;

    Term(int coeff, int exp) {
        coefficient = coeff;
        exponent = exp;
        next = nullptr;
    }
};

class Polynomial {
private:
    Term* head;
public:
    Polynomial();
    ~Polynomial();
    void insertTerm(int coeff, int exp);
    void display();
    Polynomial add(Polynomial& poly);
    Polynomial multiply(Polynomial& poly);
    static Polynomial getPolynomial();
};
