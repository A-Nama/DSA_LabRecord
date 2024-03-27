#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List
template <class T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert_at_beginning(T value);
    void insert_at_end(T value);
    void insert_at_position(T value, int position);

    void delete_from_beginning();
    void delete_from_end();
    void delete_from_position(int position);

    void display();
};

// Circular Linked List
template <class T>
class CircularLinkedList {
private:
    Node<T>* head;

public:
    CircularLinkedList();
    ~CircularLinkedList();

    void insert_at_beginning(T value);
    void insert_at_end(T value);
    void insert_at_position(T value, int position);

    void delete_from_beginning();
    void delete_from_end();
    void delete_from_position(int position);

    void display();
};

// Circular Doubly Linked List
template <class T>
class CircularDoublyLinkedList {
private:
    Node<T>* head;

public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();

    void insert_at_beginning(T value);
    void insert_at_end(T value);
    void insert_at_position(T value, int position);

    void delete_from_beginning();
    void delete_from_end();
    void delete_from_position(int position);

    void display();
};
