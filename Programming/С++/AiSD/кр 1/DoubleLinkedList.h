#pragma once
#include<iostream>
template <typename T>

class DoubleLinkedList
{
private:
	struct Node
	{
		T key;
		Node* next;
		Node* previous;
		Node(T value) : key(value), next(nullptr), previous(nullptr) {};
	};
	Node* head;
	Node* tail;

public:
	DoubleLinkedList() : head(nullptr), tail(nullptr) {};

	~DoubleLinkedList()
	{
		Node* ptr = head;
		while (head)
		{
			head = head->next;
			delete ptr;
			ptr = head;
		}
	}

	DoubleLinkedList(const DoubleLinkedList& list) = delete;

	DoubleLinkedList& operator=(const DoubleLinkedList& list) = delete;

	void reverce()
	{
		Node* ptr = head;
		Node* temp = nullptr;
		if (!head) std::cout<< "ћетод reverce не выполнен - список пуст\n";
		else
		{
			while (ptr)
			{
				temp = ptr->previous;
				ptr->previous = ptr->next;
				ptr->next = temp;
				ptr = ptr->previous;

			}
			if (temp != nullptr)
				head = temp->previous;
		}
	}

	void insert(const T value)
	{
		Node* new_element = new Node(value);
		if (!head)
			head = new_element;
		else
		{
			Node* ptr = head;
			while (ptr->next) ptr = ptr->next;
			ptr->next = new_element;
			new_element->previous = ptr;
		}
	}
	
	void print() const
	{
		if (!head) std::cout << "Ёлементы еще не добавлены\n";
		else
		{
			Node* ptr = head;
			while (ptr) {
				std::cout << ptr->key << " ";
				ptr = ptr->next;
			}
			std::cout << std::endl;
		}
	}
};

