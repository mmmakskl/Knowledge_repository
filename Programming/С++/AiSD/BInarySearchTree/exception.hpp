#pragma once
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <iostream>
#include <exception>

//!Stack exception
class StackOverflow : public std::exception
{
private:
    const char* reason_;
public:
    StackOverflow() : reason_("Stack Overflow") {}
    const char* what() const noexcept override { return reason_; }
};

class StackUnderflow : public std::exception
{
private:
    const char* reason_;
public:
    StackUnderflow() : reason_("Stack Underflow") {}
    const char* what() const noexcept override { return reason_; }
};

class WrongStackSize : public std::exception
{
private:
    const char* reason_;
public:
    WrongStackSize() : reason_("Wrong Stack Size") {}
    const char* what() const noexcept override { return reason_; }
};

//!Queue exception
class QueueOverflow : public std::exception
{
private:
    const char* reason_;
public:
    QueueOverflow() : reason_("Queue Overflow") {}
    const char* what() const noexcept override { return reason_; }
};

class QueueUnderflow : public std::exception
{
private:
    const char* reason_;
public:
    QueueUnderflow() : reason_("Queue Underflow") {}
    const char* what() const noexcept override { return reason_; }
};

class WrongQueueSize : public std::exception
{
private:
    const char* reason_;
public:
    WrongQueueSize() : reason_("Wrong Queue Size") {}
    const char* what() const noexcept override { return reason_; }
};


#endif