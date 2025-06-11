#ifndef PRIORITY_LINKEDLIST_H
#define PRIORITY_LINKEDLIST_H

#include <iostream>
#include "PriorityNode.h"

template <class T>
class PriorityLinkedList
{
private:
    Node<T> *head, *tail;

public:
    PriorityLinkedList()
    {
        this->head = this->tail = nullptr;
    }

    Node<T>* getHead() const
    {
        return this->head;
    }
    Node<T>* getTail() const
    {
        return this->tail;
    }

    bool isEmpty() const
    {
        return this->head == nullptr;
    }

    void insert(T nodeData, int priority = 0)
    {
        Node<T>* node = new Node<T>(nodeData, priority);

        if (this->head == nullptr || this->head->getPriority() < priority)
        {
            node->setNext(this->head);
            this->head = node;
            if (this->tail == nullptr)
                this->tail = node;
            return;
        }

        Node<T>* current = this->head;

        while (current->getNext() != nullptr && current->getNext()->getPriority() >= priority)
            current = current->getNext();

        node->setNext(current->getNext());
        current->setNext(node);

        if (node->getNext() == nullptr)
            this->tail = node;
    }

    T remove ()
    {
        if (this->isEmpty())
        {
            std::cerr << "List is empty. Cannot remove element." << std::endl;
            return T(); // Return default value of T
        }

        T data = this->head->getData();
        Node<T>* temp = this->head;
        this->head = this->head->getNext();
        delete temp;
        return data;
    }

    void display() const
    {
        if (this->isEmpty())
        {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node<T>* current = this->head;

        short int i = 0;
        while (current != nullptr)
        {
            (i % 3 == 0) ? std::cout << std::endl : std::cout << "";
            std::cout << "(" << current->getData() << " : " << current->getPriority() << ")\t";
            current = current->getNext();
            i++;
        }
        std::cout << std::endl << std::endl;
    }

    int totalElements() const
    {
        int count = 0;
        Node<T>* current = this->head;

        while (current != nullptr)
        {
            count++;
            current = current->getNext();
        }
        return count;
    }

    ~PriorityLinkedList()
    {
        Node<T>* temp = this->head;

        while (this->head != nullptr)
        {
            this->head = this->head->getNext();
            delete temp;
            temp = this->head;
        }
    }
};

#endif // PRIORITY_LINKEDLIST_H
