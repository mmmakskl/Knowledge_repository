#ifndef STACK_H
#define STACK_H

#include<iostream>
#include <exception>
#include<string>
#include<regex>
#include"Functions.h"
#define SIZE_MAX 100


bool checkInput(const std::string& value);

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
public:
	virtual ~Stack() {};
	virtual void push(const T& value) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
};

template <typename T>

class StackArray : protected Stack<T>
{
	
private:
	size_t size;
	int top;
	T* stack;
public:
	StackArray(const std::string& length)
	{
		if (checkInput(length) && std::stoi(length) > 0 && std::stoi(length) <= SIZE_MAX)
		{
			size = std::stoi(length);
			top = 0;
			try
			{
				stack = new T[size + 1];
			}
			catch(...)
			{
				throw WrongStackSize();
			}
		}
		else throw WrongStackSize();
	}

	~StackArray() { delete[] stack; };

	void push(const T& value) override
	{
		if (top == size) throw StackOverflow();
		else stack[++top] = value;
	}
	T pop() override
	{
		if (isEmpty()) throw StackUnderflow();
		else return stack[top--];
	}
	bool isEmpty() { return top == 0 ? true : false;  }

	void print()
	{
		if (!isEmpty())
		{
			std::cout << "Stack:  ";
			for (int i = top; i > 0; --i)
				std::cout << stack[i] << " ";
			std::cout << "\n";
		}
		else std::cout << "Стек пуст\n";
	}
};


#endif