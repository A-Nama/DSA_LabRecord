#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <class T>
class LinkedListQueue {
private:
    Node<T>* front;
    Node<T>* rear;
    int maxSize; 
    int size;    

public:
    LinkedListQueue(int);
    ~LinkedListQueue();

    void enqueue(T value);
    T dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};
