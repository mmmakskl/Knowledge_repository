#pragma once
#include<iostream>
#include<string>

template <typename T>

class DictionaryList
{
private:
	struct Node
	{
		T key;
		Node* next;
		Node(T value) : key(value), next(nullptr) {};
	};
	Node* head;
public:
	DictionaryList() : head(nullptr) {};
	~DictionaryList()
	{
		while (head)
		{
			Node* ptr = head;
			head = head->next;
			delete ptr;
		}
	};
	void insert(const T value)
	{
		if (!head) head = new Node(value);
		else
			if (!search(value))
			{
				Node* new_element = new Node(value);
				if (head->key > value)
				{
					new_element->next = head;
					head = new_element;
				}
				else
				{
					Node* next = head->next;
					Node* previous = head;
					while (next && (next->key < value))
					{
						next = next->next;
						previous = previous->next;
					}
					previous->next = new_element;
					new_element->next = next;
				}
			}
	}
	void remove(const T value)
	{
		if (!head) std::cout << "—ловарь пуст. Ёлемент не может быть удален\n";
		else
			if (search(value))
			{
				if (head->key == value) head = head->next;
				Node* ptr = head;
				while (ptr->next != search(value)) ptr = ptr->next;
				ptr->next = search(value)->next;
				delete search(value);
			}
			else std::cout << "Ёлемент не может быть удален - отсутствует в словаре\n";
	}
	Node* search(const T value) const
	{
		Node* ptr = head;
		while (ptr != nullptr && ptr->key != value) ptr = ptr->next;
		return ptr == nullptr ? nullptr : ptr;
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

	void merge(DictionaryList& list)
	{
		Node* ptr2 = list.head;
		while (ptr2)
		{
			if (head->key > ptr2->key && !search(ptr2->key))
			{
				Node* temp = ptr2;
				ptr2 = ptr2->next;
				temp->next = head;
				head = temp;
			}
			else
			{
				Node* ptr1 = head->next;
				Node* previous = head;
				while (ptr1 && ptr2)
				{
					if (search(ptr2->key))  ptr2 = ptr2->next;
					else
					{
						if (ptr1->key > ptr2->key)
						{
							Node* temp = ptr2;
							ptr2 = ptr2->next;
							temp->next = ptr1;
							previous->next = temp;

						}
						previous = previous->next;
						if (ptr2 && ptr1->key < ptr2->key) ptr1 = ptr1->next;
					}
				}
				while (ptr2)
				{
					previous->next = ptr2;
					previous = previous->next;
					ptr2 = ptr2->next;
				}
			}
		}
		ptr2 = list.head;
		list.head = list.head->next;
		while (ptr2)
		{
			list.head = list.head->next;
			ptr2 = nullptr;
			ptr2 = list.head;
		}
	}
	void deleteWords(const DictionaryList& list)
	{
		Node* ptr = list.head;
		while (ptr)
		{
			if (search(ptr->key)) remove(ptr->key);
			ptr = ptr->next;
		}
	}

	DictionaryList* getIntersection(const DictionaryList& list)
	{
		DictionaryList<T>* new_list = new DictionaryList;
		Node* ptr = list.head;
		while (ptr)
		{
			if (search(ptr->key))
				new_list->insert(ptr->key);
			ptr = ptr->next;
		}
		return new_list;
	}

};