#ifndef PRIORITY_ARRAY_LINKED_LIST_QUEUE_H
#define PRIORITY_ARRAY_LINKED_LIST_QUEUE_H

#include <iostream>
#include "../../LinkedList/LinkedList.h"

using namespace std;

template <typename T>
class PriorityArrayLinkedListQueue {
private:
    int totalPriorities;
    LinkedList<T>* list;
public:
    PriorityArrayLinkedListQueue(int totalPriorities = 10) 
    : totalPriorities(totalPriorities) {
        if (totalPriorities <= 0) {
            cerr << "Total priorities must be greater than 0." << endl;
            this->totalPriorities = 10; // Default value
        }

        this->list = new LinkedList<T>[totalPriorities];

        for (int i = 0; i < totalPriorities; ++i) {
            list[i] = LinkedList<T>();
        }
    }

    void enqueue(const T& data, int priority) {
        if (priority < 0 || priority >= totalPriorities) {
            cerr << "Invalid priority. Must be between 0 and " << totalPriorities - 1 << "." << endl;
            return;
        }
        list[priority].addToTail(data);
    }

    T dequeue() {
        for (int i = totalPriorities - 1; i >= 0; --i) {
            if (!list[i].isEmpty()) {
                T data = list[i].getHead()->getData();
                list[i].removeFromHead();
                return data;
            }
        }
        cerr << "Queue is empty. Cannot dequeue." << endl;
        return T(); // Return default value of T
    }

    bool isEmpty() const {
        for (int i = 0; i < totalPriorities; ++i) {
            if (!list[i].isEmpty()) {
                return false;
            }
        }
        return true;
    }

    int totalElements() const {
        int count = 0;
        for (int i = 0; i < totalPriorities; ++i) {
            count += list[i].totalElements();
        }
        return count;
    }

    ~PriorityArrayLinkedListQueue() {
        delete[] list;
    }

    void display() const {
        for (int i = 0; i < totalPriorities; ++i) {
            cout << "Priority " << i << ": ";
            Node<T>* current = list[i].getHead();
            while (current != nullptr) {
                cout << current->getData() << " ";
                current = current->getNext();
            }
            cout << endl;
        }
    }

    T peek() const {
        for (int i = totalPriorities - 1; i >= 0; --i) {
            if (!list[i].isEmpty()) {
                return list[i].getHead()->getData();
            }
        }
        cerr << "Queue is empty. Cannot peek." << endl;
        return T(); // Return default value of T
    }

    T getRear() const {
        for (int i = 0; i < totalPriorities; ++i) {
            if (!list[i].isEmpty()) {
                return list[i].getTail()->getData();
            }
        }
        cerr << "Queue is empty. Cannot get rear." << endl;
        return T(); // Return default value of T
    }

};

#endif // PRIORITY_ARRAY_LINKED_LIST_QUEUE_H