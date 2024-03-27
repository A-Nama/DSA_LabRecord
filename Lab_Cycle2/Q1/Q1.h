#include<iostream>
using namespace std;

template<class T>
class Stack{
    T s[100];
    int top;
    int maxSize;

public:
    Stack(int);
    void create_stack();
    void display_stack();
    void push(T);
    void pop();
    bool isEmpty();
    bool isFull();
};