#include"Q8.h"
#include <stack>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

string infixToPostfix(const std::string& infix) {
    string postfix = "";
    stack<char> opStack;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop
                ();
            }
            opStack.pop(); 
        } else if (isOperator(c)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

string infixToPrefix(const std::string& infix) {
    string reversedInfix = infix;
    string prefix = "";

    for (int i = reversedInfix.length() - 1; i >= 0; --i) {
        if (reversedInfix[i] == '(')
            reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')')
            reversedInfix[i] = '(';
        prefix += reversedInfix[i];
    }

    string reversedPostfix = infixToPostfix(prefix);

    prefix = "";
    for (int i = reversedPostfix.length() - 1; i >= 0; --i) {
        prefix += reversedPostfix[i];
    }

    return prefix;
}
