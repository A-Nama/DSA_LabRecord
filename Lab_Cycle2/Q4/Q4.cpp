#include "Q4.h"

template <class T>
LinkedListQueue<T>::LinkedListQueue(int maxSize) {
    front = nullptr;
    rear = nullptr;
    this->maxSize = maxSize ;
    size = 0;
}

template <class T>
LinkedListQueue<T>::~LinkedListQueue() {
    while (front != nullptr) {
        Node<T>* temp = front;
        front = front->next;
        delete temp;
    }
}

template <class T>
void LinkedListQueue<T>::enqueue(T value) {
    if (isFull()) {
        cerr << "Queue overflow." << endl;
        exit(1);  
    }

    Node<T>* newNode = new Node<T>(value);
    if (rear == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}


template <class T>
T LinkedListQueue<T>::dequeue() {
    if (isEmpty()) {
        cerr << "Que underflow" << endl;
        exit(1);
    }

    T value = front->data;
    Node<T>* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    size--;
    return value;
}

template <class T>
bool LinkedListQueue<T>::isEmpty() {
    return front == nullptr;
}

template <class T>
bool LinkedListQueue<T>::isFull() {
    return size == maxSize;
}

template <class T>
void LinkedListQueue<T>::display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node<T>* current = front;
    cout << "Queue: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
