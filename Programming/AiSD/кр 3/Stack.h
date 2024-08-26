#pragma once
#include<string>
#include <exception>

#define SIZE_MAX 100

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

template <typename T>

class Stack
{

private:
	int top;
	T* stack;
public:
	Stack()
	{
		stack = new T [SIZE_MAX + 1];
		int top = 0;
	}

	~Stack() { delete[] stack; };

	void push(const T value) 
	{
		if (top == SIZE_MAX) throw StackOverflow();
		else stack[++top] = value;
	}
	T pop()
	{
		if (isEmpty()) throw StackUnderflow();
		else return stack[top--];
	}
	bool isEmpty() { return top == 0 ? true : false; }

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

