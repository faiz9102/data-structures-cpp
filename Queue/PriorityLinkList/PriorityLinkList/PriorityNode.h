#ifndef PRIORITY_LINKEDLIST_NODE_H
#define PRIORITY_LINKEDLIST_NODE_H

template <class T>
class Node
{
private:
    int priority;
    T data;
    Node<T>* next;
public:
    Node(T data, int priority = 0)
    {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }

    Node ()
    {
        this->data = T();
        this->next = nullptr;
    }

    Node<T>* getNext()
    {
        return this->next;
    }

    void setNext(Node<T>* next)
    {
        this->next = next;
    }

    T getData()
    {
        return this->data;
    }

    void setData(T data)
    {
        this->data = data;
    }

    int getPriority()
    {
        return this->priority;
    }
    void setPriority(int priority)
    {
        this->priority = priority;
    }

    void display()
    {
        std::cout << std::endl << (this->data, this->priority);
    }
};

#endif // PRIORITY_LINKEDLIST_NODE_H