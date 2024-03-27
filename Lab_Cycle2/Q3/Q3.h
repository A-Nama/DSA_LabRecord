#include <iostream>
using namespace std;

template<class T>
class Queue{
    int capacity,size;
    T *arr;
    int front;
    int rear;

    public:
    Queue(int);
    ~Queue();
    void enqueue(T);
    T dequeue();
    bool isEmpty();
    bool isFull();
    void display();

};