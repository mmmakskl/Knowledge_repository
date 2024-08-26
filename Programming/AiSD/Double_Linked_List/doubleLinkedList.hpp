#pragma once
#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include <iostream>

template<typename T>
class doubleLinkedList
{
private:

    void DeleteList()
    {
        Node<T> *current = head_;
        Node<T> *next = nullptr;
        while (current)
        {
            next = current->pNext_;
            delete current;
            current = next;
        }
        head_ = nullptr;
    }

    template<typename U>
    class Node
    {
    public:
        T data_;
        Node<T>* pPrev_;
        Node<T>* pNext_;
        Node(T data, Node<T>* pPrev = nullptr, Node<T>* pNext = nullptr)
        {
            this->data_ = data;
            this->pPrev_ = pPrev;
            this->pNext_ = pNext;
        }
    };

    std::size_t size_;
    Node<T>* head_;
    Node<T>* tail_;
    
public:
    doubleLinkedList() : size_(0), head_(nullptr), tail_(nullptr) {};
    doubleLinkedList(const doubleLinkedList&) = delete;
    doubleLinkedList& operator=(const doubleLinkedList&) = delete;
    ~doubleLinkedList();

    void insertHead(T data);
    void insertTail(T data);
    void deleteLess();
    template<typename U>
    friend std::ostream& operator << (std::ostream& out, const doubleLinkedList<U>& list);
};

template<typename T>
doubleLinkedList<T>::~doubleLinkedList()
{
    DeleteList();
}

template<typename T>
void doubleLinkedList<T>::insertHead(T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->pNext_ = head_;
    if(head_)
        head_->pPrev_ = newNode;
    else
        tail_ = newNode;
    head_ = newNode;
    size_++;
}

template<typename T>
void doubleLinkedList<T>::insertTail(T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->pPrev_ = head_;
    if(tail_)
        tail_->pNext_ = newNode;
    else
        head_ = newNode;
    tail_ = newNode;
    size_++;
}

template<typename T>
void doubleLinkedList<T>::deleteLess()
{
    Node<T> *current = head_;
    Node<T> *prev = nullptr;
    while (current)
    {
        Node<T> *next = current->pNext_;
        bool deleteCurrent = 0;
        if(prev)
        {
            if(current->data_ < prev->data_)
                deleteCurrent = 1;
        }
        if(deleteCurrent)
        {
            if(!prev)
            {
                head_ = current->pNext_;
                if (head_)
                {
                    head_->pPrev_ = nullptr;
                }
            }
            else
            {
                prev->pNext_ = current->pNext_;
                if (current->pNext_)
                {
                    current->pNext_->pPrev_ = prev;
                }
            }
            if (current == tail_)
            {
                tail_ = prev;
            }
            delete current;
            size_--; 
        }
        else
        {
            prev = current;
        }
        current = next;
    }
}

template <typename T>
std::ostream& operator << (std::ostream& out, const doubleLinkedList<T>& list)
{
    typename doubleLinkedList<T>::template Node<T>* current = list.head_;
    if(current)
    {
        out << "[";
        while (current)
        {
            if (!current->pNext_)
            {
            out << current->data_;
            current = current->pNext_;
            }
            else
            {
            out << current->data_ << ", ";
            current = current->pNext_;
            }
        }
        out << "]" << std::endl;
    }
    else
        out << "List is empty" << std::endl;
    return out;
}

void test();

#endif