#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

template <class T>
class LinkedList
{
private:
    Node<T>* head, *tail;

public:
    LinkedList()
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
    void setHead(Node<T>* head)
    {
        this->head = head;
    }
    void setTail(Node<T>* tail)
    {
        this->tail = tail;
    }

    void addToTail(T nodeData)
    {
        Node<T>* node = new Node<T>(nodeData);

        if (this->head == nullptr)
        {
            this->head = this->tail = node;
        }

        else
        {
            this->tail->setNext(node);
            this->tail = node;
        }
    }

    void addToHead(T nodeData)
    {
        Node<T>* node = new Node<T>(nodeData);

        if (this->head == nullptr)
        {
            this->head = this->tail = node;
        }
        else
        {
            node->setNext(this->head);
            this->head = node;
        }
    }

    void removeNode(T nodeData)
    {
        // error: empty list
        if (this->head == nullptr)
        {
            std::cerr << std::endl
                      << "The List is empty. Can't remove element";
            return;
        }

        Node<T>* current = this->head, targetNode = nullptr;

        // edge case: if element is the only node in the list
        if (this->head->getData() == nodeData && this->head == this->tail)
        {
            this->head = this->tail = nullptr;
            targetNode = current;
        }
        // edge case: if element is the head node
        else if (this->head->getData() == nodeData)
        {
            this->head = this->head->getNext();
            targetNode = current;
        }
        else
        {
            while (current->getNext()->getData() != nodeData && current != nullptr)
                current = current->getNext();

            // error: element not found
            if (current == nullptr)
            {
                std::cerr << std::endl
                          << "Node having data value " << nodeData << "not found.";
                return;
            }

            targetNode = current->getNext();
            current->setNext(targetNode->getNext());
        }

        delete targetNode;
    }

    void removeNode(Node<T>* nodePtr)
    {
        // error: empty list
        if (this->head == nullptr)
        {
            std::cerr << std::endl
                      << "The List is empty. Can't remove element";
            return;
        }

        Node<T>* current = this->head, targetNode = nullptr;

        // edge case: if element is the only node in the list
        if (this->head == nodePtr && this->head == this->tail)
        {
            this->head = this->tail = nullptr;
            targetNode = current;
        }
        // edge case: if element is the head node
        else if (this->head == nodePtr)
        {
            this->head = this->head->getNext();
            targetNode = current;
        }
        else
        {
            while (current->getNext() != nodePtr && current != nullptr)
                current = current->getNext();

            // error: element not found
            if (current == nullptr)
            {
                std::cerr << std::endl
                          << "Node having memory address " << nodePtr << "not found.";
                return;
            }

            targetNode = current->getNext();
            current->setNext(targetNode->getNext());
        }

        delete targetNode;
    }

    void removeFromHead()
    {
        // error: empty list
        if (this->head == nullptr)
        {
            std::cerr << std::endl
                      << "The List is empty. Can't remove element";
            return;
        }

        Node<T>* temp = this->head;

        if (this->head == this->tail)
        {
            this->head = this->tail = nullptr;
        }
        else
        {
            this->head = this->head->getNext();
        }

        delete temp;
    }

    void removeFromTail()
    {
        // error: empty list
        if (this->head == nullptr)
        {
            std::cerr << std::endl
                      << "The List is empty. Can't remove element";
            return;
        }

        Node<T>* temp = this->head;

        if (this->head == this->tail)
        {
            this->head = this->tail = nullptr;
        }
        else
        {
            while (temp->getNext() != this->tail)
                temp = temp->getNext();

            delete this - // Assuming you have a custom Stack class (like your Queue)>tail;
                this->tail = temp;
        }

        delete temp;
    }

    bool isEmpty() const
    {
        return this->head == nullptr;
    }

    int totalElements() const
    {
        Node<T>* current = this->head;
        int count = 0;

        while (current != nullptr)
        {
            count++;
            current = current->getNext();
        }

        return count;
    }

    ~LinkedList()
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

#endif