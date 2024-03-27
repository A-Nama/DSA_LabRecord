#include "Q5.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    Node<T>* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

template <class T>
void DoublyLinkedList<T>::insert_at_beginning(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::insert_at_end(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <class T>
void DoublyLinkedList<T>::insert_at_position(T value, int position) {
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }
    if (position == 0) {
        insert_at_beginning(value);
    } else {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Invalid position." << endl;
        } else {
            newNode->next = current->next;
            if (current->next != nullptr)
                current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
            if (newNode->next == nullptr)
                tail = newNode;
        }
    }
}

template <class T>
void DoublyLinkedList<T>::delete_from_beginning() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
    } else {
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        if (head == nullptr)
            tail = nullptr;
    }
}

template <class T>
void DoublyLinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
    } else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
}

template <class T>
void DoublyLinkedList<T>::delete_from_position(int position) {
    if (head == nullptr || position < 0) {
        cout << "List is empty or invalid position. Cannot delete." << endl;
        return;
    }

    if (position == 0) {
        delete_from_beginning();
    } else {
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < position) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Invalid position. Cannot delete." << endl;
        } else {
            if (current == tail) {
                delete_from_end();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
        }
    }
}

template <class T>
void DoublyLinkedList<T>::display() {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Circular Linked List functions
template <class T>
CircularLinkedList<T>::CircularLinkedList() {
    head = nullptr;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList() {
    if (head != nullptr) {
        Node<T>* current = head;
        Node<T>* temp;
        do {
            temp = current->next;
            delete current;
            current = temp;
        } while (current != head);
    }
}

template <class T>
void CircularLinkedList<T>::insert_at_beginning(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

template <class T>
void CircularLinkedList<T>::insert_at_end(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

template <class T>
void CircularLinkedList<T>::insert_at_position(T value, int position) {
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 0) {
        insert_at_beginning(value);
    } else {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < position - 1) {
            current = current->next;
                       count++;
        }
        if (current == nullptr) {
            cout << "Invalid position." << endl;
        } else {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }
}

template <class T>
void CircularLinkedList<T>::delete_from_beginning() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
    } else if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node<T>* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete temp;
    }
}

template <class T>
void CircularLinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
    } else if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node<T>* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        delete temp;
    }
}

template <class T>
void CircularLinkedList<T>::delete_from_position(int position) {
    if (head == nullptr || position < 0) {
        cout << "List is empty or invalid position. Cannot delete." << endl;
        return;
    }

    if (position == 0) {
        delete_from_beginning();
    } else {
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < position) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Invalid position. Cannot delete." << endl;
        } else {
            if (current == head->prev) {
                delete_from_end();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
        }
    }
}

template <class T>
void CircularLinkedList<T>::display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node<T>* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// Circular Doubly Linked List functions
template <class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() {
    head = nullptr;
}

template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
    if (head != nullptr) {
        Node<T>* current = head;
        Node<T>* temp;
        do {
            temp = current->next;
            delete current;
            current = temp;
        } while (current != head);
    }
}

template <class T>
void CircularDoublyLinkedList<T>::insert_at_beginning(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

template <class T>
void CircularDoublyLinkedList<T>::insert_at_end(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

template <class T>
void CircularDoublyLinkedList<T>::insert_at_position(T value, int position) {
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 0) {
        insert_at_beginning(value);
    } else {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Invalid position." << endl;
        } else {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }
}

template <class T>
void CircularDoublyLinkedList<T>::delete_from_beginning() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
    } else if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node<T>* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        delete temp;
    }
}

template <class T>
void CircularDoublyLinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
    } else if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node<T>* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        delete temp;
    }
}

template <class T>
void CircularDoublyLinkedList<T>::delete_from_position(int position) {
    if (head == nullptr || position < 0) {
        cout << "List is empty or invalid position. Cannot delete." << endl;
        return;
    }

    if (position == 0) {
        delete_from_beginning();
    } else {
        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < position) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Invalid position. Cannot delete." << endl;
        } else {
            if (current == head->prev) {
                delete_from_end();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
        }
    }
}

template <class T>
void CircularDoublyLinkedList<T>::display() {
    if (head == nullptr || head->next == head) {
        cout << "List is empty." << endl;
        return;
    }

    Node<T>* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}
