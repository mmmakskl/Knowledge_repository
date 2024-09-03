#pragma once
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include "exception.hpp"
#include "VirtualStackAndQueue.hpp"

template<typename T>
class QueueArray : public Queue<T>
{
private:
    std::size_t size_;
    int head_ = -1;
    int tail_ = -1;
    T* array_;
public:
    QueueArray(std::size_t size = 100);
    QueueArray(const QueueArray<T>& src);
    QueueArray(QueueArray<T>&& src);
    ~QueueArray();

    QueueArray<T>& operator=(const QueueArray<T>& src);
    QueueArray<T>& operator=(QueueArray<T>&& src);

    void enQueue(const T& e) override;
    T deQueue() override;
    bool isEmpty() override;
    bool isFull();

    T& operator[](std::size_t head);
};

template <typename T>
inline QueueArray<T>::QueueArray(std::size_t size) :
    size_(size),
    tail_(-1)
{
    if(size == 0)
    {
        throw WrongQueueSize();
    }
    array_ = new T[size];
}

template <typename T>
inline QueueArray<T>::QueueArray(const QueueArray<T> &src) :
    size_(src.size_),
    tail_(src.tail_),
    head_(src.head_),
    array_(new T[src.size_])
{
    std::copy(src.array_, src.array_+src.size_, array_);
}

template <typename T>
inline QueueArray<T>::QueueArray(QueueArray<T> &&src) : 
    size_(src.size_),
    tail_(src.tail_),
    head_(src.head_),
    array_(src.array_)
{
    src.array_ = nullptr;
    src.size_ = 0;
    src.tail_ = -1;
    src.head_ = -1;
}

template <typename T>
inline QueueArray<T>::~QueueArray()
{
    delete[] array_;
}

template <typename T>
inline QueueArray<T> &QueueArray<T>::operator=(const QueueArray<T> &src)
{
    if(this != &src)
    {
        delete[] array_;
        size_ = src.size_;
        tail_ = src.tail_;
        head_ = src.head_;
        array_ = new T[src.size_ + 1];
        std::copy(src.array_, src.array_+src.size_, array_);
    }
    return *this;
}

template <typename T>
inline QueueArray<T> &QueueArray<T>::operator=(QueueArray<T> &&src)
{
    if (this != &src)
    {
        delete[] array_;
        size_ = src.size_;
        tail_ = src.tail_;
        head_ = src.head_;
        array_ = src.array_;
        src.array_ = nullptr;
        src.size_ = 0;
        src.tail_ = -1;
        src.head_ = -1;
    }
    return *this;
}

template <typename T>
inline void QueueArray<T>::enQueue(const T &e)
{
    if (isFull())
        throw QueueOverflow();
    else
    {
        if (head_ == -1) head_ = 0;
        tail_ = (tail_ + 1) % size_;
        array_[tail_] = e;
    }
}

template <typename T>
inline T QueueArray<T>::deQueue()
{
    T elem;
    if (isEmpty())
        throw QueueUnderflow();
    elem = array_[head_];
    if (head_ == tail_)
    {
        head_ = -1;
        tail_ = -1;
    }
    else
    {
        head_ = (head_ + 1) % size_;
    }
    return (elem);
}

template <typename T>
inline bool QueueArray<T>::isEmpty()
{
    return (tail_ == -1);
}

template <typename T>
inline bool QueueArray<T>::isFull()
{
    return ((head_ == 0 && tail_ == size_ - 1) || (head_ == tail_ + 1));
}


template <typename T>
T &QueueArray<T>::operator[](std::size_t head)
{
    T* array = array_;
    return array[head];
}

#endif


