#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void append(const T& value);
    void printList() const;
    Node<T>* getHead() const;
};

// Implementation of LinkedList

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    Node<T>* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <typename T>
void LinkedList<T>::append(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node<T>* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

template <typename T>
void LinkedList<T>::printList() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

template <typename T>
Node<T>* LinkedList<T>::getHead() const {
    return head;
}

#endif // LINKEDLIST_H