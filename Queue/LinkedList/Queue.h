#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <iostream>
#include "../../LinkedList/LinkedList.h"

using namespace std;

template <typename T>
class LinkedListQueue {
private:
    LinkedList<T>* list;
public:
    LinkedListQueue() {
        list = new LinkedList<T>();
    }

    ~LinkedListQueue() {
        delete list;
    }

    bool isEmpty() const {
        return list->isEmpty();
    }

    int getSize() const {
        return list->totalElements();
    }

    void enqueue(const T& value) {
        list->addToTail(value);
    }

    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            return T(); 
        }
        
        T value = list->getHead()->getData();
        list->removeFromHead();
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            return T(); 
        }
        return list->getHead()->getData();
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        Node<T>* current = list->getHead();
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }
    T getRear() const {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            return T(); 
        }
        return list->getTail()->getData();
    }
};

#endif // LINKED_LIST_QUEUE_H