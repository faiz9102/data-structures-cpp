#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <iostream>

using namespace std;

template <class T>
class QueueArray {
private:
    T* arr;
    int front;
    int rear;
    int size;
public:
    QueueArray(int size) : front(-1), rear(-1), size(size) {
        arr = new T[this->size];
    }

    ~QueueArray() {
        delete[] arr;
    }

    bool isFull() const {
        return size == rear + 1;
    }

    bool isEmpty() const {
        return rear == -1 && front == -1;
    }

    void enqueue(T value) {
        if (isFull()) {
            cerr << "Queue is full!" << endl;
            return;
        }
        
        if (isEmpty()) {
            front++;
        }
        arr[++rear] = value;
    }

    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return T();
        }

        T value = arr[front];

        if (front == rear) {
            front = rear = -1; // Reset queue when it becomes empty
        } else {
            front++;
        }
        
        return value;
    }
    T peek() const {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return T();
        }
        return arr[front];
    }

    void display() const {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T getRear() const {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return T();
        }
        return arr[rear];
    }

    int getSize() {
        return this->size;
    }
};

#endif