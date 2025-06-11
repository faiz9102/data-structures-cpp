#ifndef PRIORITY_LINKEDLIST_QUEUE_H
#define PRIORITY_LINKEDLIST_QUEUE_H

#include <iostream>
#include "./PriorityLinkList/PriorityLinkedList.h"

using namespace std;

template <typename T>
class PriorityLinkedListQueue {
private:
    PriorityLinkedList<T>* list;
public:
    PriorityLinkedListQueue() {
        list = new PriorityLinkedList<T>();
    }

    void enqueue(const T& data,int priority) {
       list->insert(data, priority);
    }

    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            return T(); 
        }
        return list->remove();
    }

    T getRear() const {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            return T(); 
        }
        return list->getTail()->getData();
    }

    T peek() const {
        if (isEmpty()) {
            cerr << "Queue is empty" << endl;
            return T(); 
        }
        return list->getHead()->getData();
    }

    bool isEmpty() const {
        return list->isEmpty();
    }

    ~PriorityLinkedListQueue() {
        delete list;
    }

    void display() const {
        this->list->display();
    }
};

#endif // PRIORITY_LINKEDLIST_QUEUE_H