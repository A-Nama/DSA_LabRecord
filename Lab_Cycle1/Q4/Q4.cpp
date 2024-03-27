#include "Q4.h"

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    Node<T>* link = nullptr;
    while (current != nullptr) {
        link = current->link;
        delete current;
        current = link;
    }
}

template <class T>
void LinkedList<T>::insert_at_beginning(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->link = head;
        head = newNode;
    }
}

template <class T>
void LinkedList<T>::insert_at_end(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->link = newNode;
        tail = newNode;
    }
}

template <class T>
void LinkedList<T>::insert_at_position(T value, int position) {
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 0) {
        insert_at_beginning(value);
    } 
    else {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < position - 1) {
            current = current->link;
            count++;
        }
        if (current == nullptr) {
            cout << "Invalid position." << endl;
        } 
        else {
            newNode->link = current->link;
            current->link = newNode;
            if (current == tail) {
                tail = newNode;
            }
        }
    }
}

template <class T>
void LinkedList<T>::delete_from_beginning() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
    } else {
        Node<T>* temp = head;
        head = head->link;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

template <class T>
void LinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
    } else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* current = head;
        while (current->link != tail) {
            current = current->link;
        }
        delete tail;
        current->link = nullptr;
        tail = current;
    }
}

template <class T>
void LinkedList<T>::delete_from_position(int position) {
    if (head == nullptr || position < 0) {
        cout << "List is empty or invalid position. Cannot delete." << endl;
        return;
    }

    if (position == 0) {
        delete_from_beginning();
    } else {
        Node<T>* current = head;
        Node<T>* previous = nullptr;
        int count = 0;
        while (current != nullptr && count < position) {
            previous = current;
            current = current->link;
            count++;
        }
        if (current == nullptr) {
            cout << "Invalid position. Cannot delete." << endl;
        } else {
            previous->link = current->link;
            delete current;
            if (previous->link == nullptr) {
                tail = previous;
            }
        }
    }
}

template <class T>
void LinkedList<T>::display() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}


