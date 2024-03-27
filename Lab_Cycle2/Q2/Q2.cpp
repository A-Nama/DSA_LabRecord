#include "Q2.h"

template <class T>
LinkedListStack<T>::LinkedListStack(int maxSize) {
    top = nullptr;
    this->maxSize = maxSize;
    size = 0;
    };


template <class T>
LinkedListStack<T>::~LinkedListStack() {
    while (top != nullptr) {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
}

template <class T>
void LinkedListStack<T>::push(T value) {
    if (size == maxSize){
        cout << "Stack Overflow " << endl;
        exit(1);
    }
    Node<T>* newNode = new Node<T>(value);
    newNode->next = top;
    top = newNode;
    size = size + 1;
}

template <class T>
T LinkedListStack<T>::pop() {
    if (isEmpty()) {
        cerr << "Stack Underflow" << endl;
    }
        T value = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        size = size - 1;
        return value;

}

template <class T>
bool LinkedListStack<T>::isEmpty() {
    return top == nullptr;
}

template <class T>
bool LinkedListStack<T>::isFull() {
        return size == maxSize;
    }

template <class T>
void LinkedListStack<T>::display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    Node<T>* current = top;
    cout << "Stack: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}