#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

template <class T>
class Node
{
private:
    T data;
    Node<T>* next;
public:
    Node(T data)
    {
        this->data = data;
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

    void display()
    {
        std::cout << std::endl << this->data;
    }
};

#endif // LINKEDLISTNODE_H