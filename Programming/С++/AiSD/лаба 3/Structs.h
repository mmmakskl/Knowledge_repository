#ifndef STRUCTS_H
#define STRUCTS_H
const std::string EMPTY_COLLECTION = "Ёлементы отсутствуют\n";

template <typename T>
struct Node
{
	T key_;
	Node<T>* next_;
	Node(T key, Node<T>* next = nullptr) : key_(key), next_(next) {};
};

template <class T>
class Queue
{
	friend struct Node<T>;
public:
	Queue(): head(nullptr) {};
	~Queue()
	{
		if (head)
		{
			Node<T>* previous = head;
			Node<T>* ptr = previous->next_;
			while (ptr)
			{
				delete previous;
				previous = ptr;
				ptr = ptr->next_;
			}
			delete previous;
		}
	}
	
	bool isEmpty() const { return !head ? true : false; }
	void push(const T key)
	{
		Node<T>* new_el = new Node<T>(key);
		if (!head) head = new_el;
		else
		{
			Node<T>* ptr = head;
			while (ptr->next_) ptr = ptr->next_;
			ptr->next_ = new_el;
		}
	}

	T getFront() 
	{
		if (head) return head->key_;
		else std::cerr << EMPTY_COLLECTION;
	};
	void pop()
	{
		Node<T>* ptr = head;
		if (head) head = head->next_;
		else std::cerr << EMPTY_COLLECTION;
		 delete ptr;
	}
private:
		Node<T>* head;
};

template <typename T>
class Stack
{
	friend struct Node<T>;
	
public:
	Stack() : top(nullptr) {}
	~Stack()
	{
		if (top)
		{
			Node<T>* previous = top;
			Node<T>* ptr = top->next_;
			while (ptr)
			{
				delete previous;
				previous = ptr;
				ptr = ptr->next_;
			}
			delete previous;
		}
	}
	bool isEmpty() const { return !top ? true : false; }
	void push(const T key) 
	{
		Node<T>* new_el = new Node<T>(key);
		if (!top) top = new_el;
		else
		{
			Node<T>* ptr = top;
			while (ptr->next_) ptr = ptr->next_;
			ptr->next_ = new_el;
		}
	}
	T getTop() const 
	{
		if (top)
		{
			Node<T>* ptr = top;
			while (ptr->next_) ptr = ptr->next_;
			return ptr->key_;
		}
		else std::cerr << EMPTY_COLLECTION;
	}
	void pop() 
	{
		if (top)
		{
			Node<T>* previous = top;
			if (previous->next_)
			{
				Node<T>* ptr = top->next_;
				while (ptr->next_)
				{
					previous = previous->next_;
					ptr = ptr->next_;
				}
				previous->next_ = nullptr;
				delete ptr;
			}
			else
			{
				top = nullptr;
				delete previous;
			}

		}
		else std::cerr << EMPTY_COLLECTION;
	}

private:
	Node<T>* top;
};

#endif