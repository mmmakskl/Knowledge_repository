#include <iostream>

template<class T>
class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(const T& e) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() = 0;
};

template<class T>
class Queue
{
public:
    virtual ~Queue() {}
    virtual void enQueue( const T& e ) = 0;
    virtual T deQueue() = 0;
    virtual bool isEmpty() = 0;
};