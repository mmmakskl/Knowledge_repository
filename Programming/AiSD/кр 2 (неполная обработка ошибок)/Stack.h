#pragma once
#include<iostream>
#include <exception>
#define SIZE_MAX 100
using namespace std;


class StackOverflow : public std::exception
{
	const std::string reason;
public:
	StackOverflow() : reason("Стек переполнен\n") {};
	const char* what() const { return reason.c_str(); }
};

class StackUnderflow : public std::exception
{
	const std::string reason;
public:
	StackUnderflow() : reason("Стек пуст\n") {};
	const char* what() const { return reason.c_str(); }
};

class WrongStackSize : public std::exception
{
	const std::string reason;
public:
	WrongStackSize() : reason("Неверный размер стека\n") {};
	const char* what() const { return reason.c_str(); }
};


template <typename T>
class Stack
{
private:
	int top;
	int size;
	T* stack;
public:
	Stack(const size_t stackSize)
	{
		if (stackSize <= SIZE_MAX)
		{
			size = stackSize;
			top = 0;
			try
			{
				stack = new T[size + 1];
			}
			catch (...)
			{
				throw WrongStackSize();
			}
		}
		else throw WrongStackSize();
	}

	~Stack() { delete[]stack; }

	void push(const int value)
	{
		if (top == size) throw StackOverflow();
		else stack[++top] = value;
	}
	T pop()
	{
		if (isEmpty()) throw StackUnderflow();
		else return stack[top--];
	}

	T gettop() const { return stack[top]; }

	void print() const
	{
		for (int i = 1; i <= top; ++i)
			std::cout << stack[i] << "\t";
		std::cout << std::endl;
	}

	bool isEmpty() const { return top == 0 ? true : false;}

};