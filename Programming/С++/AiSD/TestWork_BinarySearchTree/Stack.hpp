#pragma once
#ifndef STACK_HPP
#define STACK_HPP
#include "exception.hpp"
#include "VirtualStackAndQueue.hpp"
void test();

bool checkBalanceBrackets(const std::string& text, const std::size_t maxDeep);

template<typename T>
class StackArray : public Stack<T>
{
private:
    std::size_t size_;
    std::size_t top_;
    T* array_;
    void swap(StackArray<T>& src)
    {
        std::swap(array_, src.array_);
        std::swap(top_, src.top_);
        std::swap(size_, src.size_);
    }

public:
    StackArray(size_t size = 100);
    StackArray(const StackArray<T>& src);
    StackArray(StackArray<T>&& src);
    ~StackArray();

    StackArray<T>& operator=(const StackArray<T>& src);
    StackArray<T>& operator=(StackArray<T>&& src);

    void push(const T& e) override;
    T pop() override;
    bool isEmpty() override;

    T& top() const;
    T& operator[](size_t top);
};

template <typename T>
inline StackArray<T>::StackArray(size_t size) :
    size_(size),
    top_(0)
{
    if(size == 0)
    {
        throw WrongStackSize();
    }
    array_ = new T[size];
}

template <typename T>
inline StackArray<T>::StackArray(const StackArray<T> &src) :
    size_(src.size_),
    top_(src.top_),
    array_(new T[src.size_])
{
    std::copy(src.array_, src.array_+src.size_, array_);
}

template <typename T>
inline StackArray<T>::StackArray(StackArray<T> &&src) :
    size_(src.size_),
    top_(src.top_),
    array_(src.array_)
{
    src.array_ = nullptr;
    src.size_ = 0;
    src.top_ = 0;
}

template <typename T>
inline StackArray<T> &StackArray<T>::operator=(const StackArray<T> &src)
{
    if(this != &src)
    {
        delete[] array_;
        size_ = src.size_;
        top_ = src.top_;
        array_ = new T[src.size_ + 1];
        std::copy(src.array_, src.array_+src.size_, array_);
    }
    return *this;
}

template <typename T>
inline StackArray<T> &StackArray<T>::operator=(StackArray<T> &&src)
{
    if (this != &src)
    {
        delete[] array_;
        size_ = src.size_;
        top_ = src.top_;
        array_ = src.array_;
        src.array_ = nullptr;
        src.size_ = 0;
        src.top_ = 0;
    }
    return *this;
}

template <typename T>
inline T &StackArray<T>::top() const
{
	return array_[top_ - 1];
}

template <typename T>
inline StackArray<T>::~StackArray()
{
    delete[] array_;
}

template <typename T>
inline void StackArray<T>::push(const T &e)
{
    if (top_ == size_)
        throw StackOverflow();
    array_[top_++] = e;
}

template <typename T>
inline T StackArray<T>::pop()
{
    if (isEmpty())
        throw StackUnderflow();
    return array_[--top_];
}

template <typename T>
inline bool StackArray<T>::isEmpty()
{
    return (top_ == 0);
}

template <typename T>
T &StackArray<T>::operator[](size_t top)
{
    T* array = array_;
    return array[top-1];
}

#endif


