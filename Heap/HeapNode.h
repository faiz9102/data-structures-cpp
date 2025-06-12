#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>

using namespace std;

template <typename T>
class HeapNode {
private:
    T data;
    int Priority;
public:
    HeapNode() : data(T()), Priority(0) {}
    HeapNode(T data, int priority) : data(data), Priority(priority) {}

    T getData() const {
        return data;
    }

    int getPriority() const {
        return Priority;
    }

    void setPriority(int priority) {
        Priority = priority;
    }

    bool operator>(const HeapNode<T>& other) const {
        return Priority > other.Priority;
    }
    bool operator<(const HeapNode<T>& other) const {
        return Priority < other.Priority;
    }
    bool operator==(const HeapNode<T>& other) const {
        return Priority == other.Priority;
    }
};

#endif // HEAPNODE_H