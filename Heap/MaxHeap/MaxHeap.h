#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "../HeapNode.h"
#include <iostream>

using namespace std;

template <class T>
class MaxHeap {
private:
    HeapNode<T>* heap;
    int currentIndex;
    int size;
public:
    MaxHeap(int size) {
        this->currentIndex = 0;
        this->size = size;
        this->heap = new HeapNode<T>[size];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(const T& data, int priority) {
        if(currentIndex < size) {
            heap[++currentIndex] = HeapNode<T>(data, priority);
            reHeapifyUpward(currentIndex);
        } else {
            cerr << "Heap is full, cannot insert new element." << endl;
        }
    }

    void remove() {
        if (currentIndex >= 1) {
            heap[1] = heap[currentIndex--];
            reHeapifyDownward();
        } else {
            cerr << "Heap is empty, cannot remove element." << endl;
        }
    }

    void reHeapifyUpward(int index) {
        while (index > 1 && heap[index] > heap[index / 2]) {
            swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }
    void reHeapifyDownward(int index = 1) {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= currentIndex && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right <= currentIndex && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            reHeapifyDownward(largest);
        }
    }

    void heapSort() {
        const int originalSize = currentIndex;
        for (int i = originalSize; i > 1; i--) {
            swap(heap[1], heap[i]);
            currentIndex--;
            reHeapifyDownward(1);
        }
        currentIndex = originalSize;
    }

    void printHeap() const {
        cout << endl;
        for (int i = 1; i <= currentIndex; i++) {
            cout << heap[i].getPriority() << "\t";
        }
    }
};

#endif // MAX_HEAP_H