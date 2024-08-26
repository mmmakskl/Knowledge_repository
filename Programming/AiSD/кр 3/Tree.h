#pragma once
#include <iostream>
#include"Stack.h"

const std::string EMPTY_COLLECTION = "Ёлементы отсутствуют\n";

template<typename T>
class BinarySearchTree
{
public:
	template<typename T>
	struct Node
	{
		T key_;
		Node<T>* left_;
		Node<T>* right_;
		Node<T>* p_;
		Node(T key, Node<T>* left = nullptr, Node<T>* right = nullptr, Node<T>* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p) {};
		Node(const Node<T>&& other) noexcept
		{
			left_ = other.left_;
			other.left_ = nullptr;
			right_ = other.rigth_;
			other.rigth_ = nullptr;
			key_ = other.key_;
			p_ = other.p_;
			other.p_ = nullptr;
		}
	};
	Node<T>* root;
	BinarySearchTree() : root(nullptr) {};
	virtual ~BinarySearchTree() { deleteNodes(root); }
	bool insertNode(const T& key)
	{
		Node<T>* new_element = new Node<T>(key);
		if (!root)
		{
			root = new_element;
			return true;
		}
		else
		{
			Node<T>* ptr = root;
			while (ptr)
			{
				Node<T>* p_ptr = ptr;
				if (key < ptr->key_)
				{
					if (!ptr->left_)
					{
						ptr->left_ = new_element;
						new_element->p_ = ptr;
						return true;
					}
					ptr = ptr->left_;
				}
				else if (key > ptr->key_)
				{
					if (!ptr->right_)
					{
						ptr->right_ = new_element;
						new_element->p_ = ptr;
						return true;
					}
					ptr = ptr->right_;
				}
				else
				{
					delete new_element;
					return false;
				}

			}

		}
	}
	void output(std::ostream& out) const
	{
		if (!root) throw std::runtime_error( EMPTY_COLLECTION);
		else
		{
			output(out, root);
			out << "\n";
		}
	}

	int findMinLeafKey()
	{
		if (root == nullptr) 		throw std::runtime_error(EMPTY_COLLECTION);

		Stack<Node <T>*> nodesStack;
		Node<T>* ptr = root;
		int minKey = INT_MAX; 

		while (ptr || !nodesStack.isEmpty()) 
		{
			while (ptr) 
			{
				nodesStack.push(ptr);
				ptr = ptr->left_;
			}
			ptr = nodesStack.pop();

			if (!ptr->left_  && !ptr->right_ )
			{
				minKey = std::min(minKey, ptr->key_);
			}

			ptr = ptr->right_;
		}

		return minKey;
	}

	int findMinLeafKeyRecursive()
	{
		int result = find_MinLeafKeyRecursive(root);
		if (result == INT_MAX)
			throw std::runtime_error(EMPTY_COLLECTION);
		else return result;
	}

	
private:
		
	void output(std::ostream& out, Node<T>* ptr) const
	{
		if (!ptr) return;
		out << ptr->key_;
		if (ptr->left_ != nullptr || ptr->right_ != nullptr)
		{
			out << " (";
			output(out, ptr->left_);
			if (ptr->left_ && ptr->right_) out << ", ";
			output(out, ptr->right_);
			out << ")";
		}
	}
	void deleteNodes(Node<T>* node)
	{
		if (!node) return;
		else
		{
			deleteNodes(node->left_);
			deleteNodes(node->right_);
			delete node;
		}
	}
	int find_MinLeafKeyRecursive(Node<T>* ptr) 
	{
		if (!ptr) return INT_MAX;
		else
		{
			if (!ptr->left_ && !ptr->right_)  return ptr->key_;
			else
			{
				int leftMin = find_MinLeafKeyRecursive(ptr->left_);
				int rightMin = find_MinLeafKeyRecursive(ptr->right_);
				return std::min(leftMin, rightMin);
			}
			
		}
	}
	
};