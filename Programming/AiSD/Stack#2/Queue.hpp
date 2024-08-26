#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include "exception.hpp"
#include "abstract.hpp"

template<class T>
class QueueArray : public Queue<T>
{
private:
    std::size_t size_;
    std::size_t head_;
    std::size_t tail_;
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

    std::size_t getTail();
    std::size_t getHead();
    std::size_t getSize();
    T& operator[](std::size_t head);
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const QueueArray<U>& Queue);
};

template <typename T>
QueueArray<T>::QueueArray(std::size_t size) :
    size_(size),
    head_{0},
    tail_(0)
{
    if(size == 0)
    {
        throw WrongQueueSize();
    }
    array_ = new T[size];
}

template <typename T>
QueueArray<T>::QueueArray(const QueueArray<T> &src) :
    size_(src.size_),
    tail_(src.tail_),
    head_(src.head_),
    array_(new T[src.size_])
{
    std::copy(src.array_, src.array_+src.size_, array_);
}

template <typename T>
QueueArray<T>::QueueArray(QueueArray<T> &&src) :
    size_(src.size_),
    tail_(src.tail_),
    head_(src.head_),
    array_(src.array_)
{
    src.size_ = 0;
    src.tail_ = 0;
    src.head_ = 0;
    src.array_ = nullptr;
}

template <typename T>
QueueArray<T>::~QueueArray()
{
    delete[] array_;
}

template <typename T>
QueueArray<T> &QueueArray<T>::operator=(const QueueArray<T> &src)
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
QueueArray<T> &QueueArray<T>::operator=(QueueArray<T> &&src)
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
        src.tail_ = 0;
        src.head_ = 0;
    }
    return *this;
}

template <typename T>
void QueueArray<T>::enQueue(const T &e)
{
    if (tail_ == 0 && head_ == 0)
    {
        tail_ = (tail_) % size_;
        array_[tail_] = e;
        tail_++;
    }
    else if (isFull())
        throw QueueOverflow();
    else
    {
        tail_ = (tail_) % size_;
        array_[tail_] = e;
        tail_++;
    }
}

template <typename T>
T QueueArray<T>::deQueue()
{
    T elem;
    if (isEmpty())
        throw QueueUnderflow();
    elem = array_[head_];
    if (head_ == tail_)
    {
        head_ = 0;
        tail_ = 0;
    }
    else
    {
        head_ = (head_) % size_;
        head_++;
    }
    return (elem);
}

template <typename T>
bool QueueArray<T>::isEmpty()
{
    return (tail_ == 0);
}

template <typename T>
bool QueueArray<T>::isFull()
{
    return ((head_ == 0 && tail_ == std::size_t(size_ + 1)) || (head_ == tail_));
}

template <typename T>
std::size_t QueueArray<T>::getTail()
{
    return tail_;
}

template <typename T>
std::size_t QueueArray<T>::getHead()
{
    return head_;
}

template <typename T>
std::size_t QueueArray<T>::getSize()
{
    return size_;
}

template <typename T>
T &QueueArray<T>::operator[](std::size_t head)
{
    T* array = array_;
    return array[head];
}

template <typename T>
std::ostream &operator<<(std::ostream &out, QueueArray<T>& queue)
{
    std::size_t i = 0;
    if (queue.isEmpty())
    {
        out << "- Queue is empty" << std::endl;
        return out;
    }
    out << "<- ";
    for (i = queue.getHead(); i+1 != queue.getTail(); i = i % queue.getSize())
    {
        out << queue[i] << ", ";
        i++;
    }
    out << queue[i];
    out << "]" << std::endl;
    return out;
}
#endif


