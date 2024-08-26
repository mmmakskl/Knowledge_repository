#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include <exception>
#include<string>
#include<regex>
#define SIZE_MAX 100

bool checkInput(const std::string& value);

class QueuekOverflow : public std::exception
{
	const std::string reason;
public:
	QueuekOverflow() : reason("Очередь переполнена\n") {};
	const char* what() const { return reason.c_str(); }
};

class QueueUnderflow : public std::exception
{
	const std::string reason;
public:
	QueueUnderflow() : reason("Очередь пуста\n") {};
	const char* what() const { return reason.c_str(); }
};

class WrongQueueSize : public std::exception
{
	const std::string reason;
public:
	WrongQueueSize() : reason("Неверный размер очереди\n") {};
	const char* what() const { return reason.c_str(); }
};


template <typename T>
class Queue
{
public:
	virtual ~Queue() {};
	virtual void enQueue(const T& value) = 0;
	virtual T deQueue() = 0;
	virtual bool isEmpty() = 0;
};


template <typename T>
class CircularQueue :protected Queue<T>
{
private:
	int head;
	int tail;
	size_t size;
	T* queue;
public:
	CircularQueue(const std::string& length)
	{
		if (checkInput(length) && std::stoi(length) > 0 && std::stoi(length) <= SIZE_MAX)
		{
			size = std::stoi(length);
			head = 0;
			tail = head;
			try
			{
				queue = new T[size + 1];
			}
			catch (...)
			{
				throw WrongQueueSize();
			}
		}
		else throw WrongQueueSize();
	}
	~CircularQueue() override { delete[] queue; }
	void enQueue(const T& value) override
	{
		if (tail + 1 <= size)
			 queue[tail++] = value;
		else throw QueuekOverflow();
	};
	T deQueue() override
	{
		if (!isEmpty())
		{
			T result = queue[head];
			for (int i = 0; i < tail; ++i)
				std::swap(queue[i], queue[i + 1]);
			--tail;
			return queue[result];
		}
		else throw QueueUnderflow();
	};
	bool isEmpty() override {	return head == tail; };

	void print()
	{
		if (!isEmpty())
		{
			std::cout << "Queue:  ";
			for (int i = head; i < tail; ++i)
				std::cout << queue[i] << " ";
			std::cout << "\n";
		}
		else std::cout << "Очередь пуста\n";
	}


};

#endif