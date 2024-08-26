#pragma once
#include <iostream>

template<typename T>
class Stack
{
public:
    virtual ~Stack() {}
    virtual void push(const T& e) = 0;
    virtual T pop() = 0;
    virtual bool isEmpty() = 0;
};

template<typename T>
class Queue
{
public:
    virtual ~Queue() {}
    virtual void enQueue( const T& e ) = 0;
    virtual T deQueue() = 0;
    virtual bool isEmpty() = 0;
};