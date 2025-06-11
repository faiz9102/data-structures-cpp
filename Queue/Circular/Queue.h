#ifndef ARRAY_CIRCULAR_QUEUE_H
#define ARRAY_CIRCULAR_QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class CircularQueue {
private:
    T* arr;
    int front;
    int rear;
    int size;
public:
    CircularQueue(int size) : front(-1), rear(-1), size(size) {
        arr = new T[this->size];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (rear + 1) % size == front;
    }

    void enqueue(const T& value) {
        if (isFull()) {
            cerr << "Queue is full!" << endl;
            return;
        }

        if (front == -1) {
            front++;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        return;
    }

    T dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return T();
        } else if (front == rear) {
            T value = arr[front];
            front = rear = -1;
            return value;
        }

        T value = arr[front];
        front = (front + 1) % size;
        return value;
    }

    int getSize() const {
        return this->size;
    }

    T peek() const {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return T();
        }
        return arr[front];
    }
    T getRear() const {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return T();
        }
        return arr[rear];
    }
    void display() const {
        if (isEmpty()) {
            cerr << "Queue is empty!" << endl;
            return;
        }

        int i = front;
        std::cout << "Queue elements: ";
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        std::cout << std::endl;
    }
};

#endif // ARRAY_CIRCULAR_QUEUE_H