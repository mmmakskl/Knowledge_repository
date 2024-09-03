#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <sstream>
#include"Structs.h"


template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree(): root(nullptr) {};
	BinarySearchTree(const BinarySearchTree& scr) = delete;
	BinarySearchTree( BinarySearchTree&& other) noexcept
	{ 
		root = other.root;
		other.root = nullptr;
	}
	BinarySearchTree& operator = (const BinarySearchTree& scr) = delete;
	BinarySearchTree& operator = (const BinarySearchTree&& other) noexcept
	{
		root = other.root;
		other.root = nullptr;
		return *this;
	}
	virtual ~BinarySearchTree() { deleteNodes(root); }

	bool searchKeyIterative(const T& key) const
	{
		Node<T>* ptr = root;
		if (!root)
		{
			std::cerr << EMPTY_COLLECTION;
			return false;
		}
		else
			while (ptr != nullptr && ptr->key_ != key)
			{
				if (key < ptr->key_) ptr = ptr->left_;
				else ptr = ptr->right_;
			}
		return (ptr != nullptr && ptr->key_ == key) ? true : false;
	}

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
		if (!root) std::cerr << EMPTY_COLLECTION;
		else
		{
			output(out, root); 
			out << "\n";
		}
	}

	bool deleteNode(const T& key)
	{
		if(!searchNodeIterative(key)) return false;
		else
		{
			Node<T>* ptr = searchNodeIterative(key);

			if (!ptr->left_ && !ptr->right_)
			{
				if (ptr->p_->left_ && ptr->p_->left_->key_ == key) ptr->p_->left_ = nullptr;
				else  if (ptr->p_->right_ && ptr->p_->right_->key_ == key) ptr->p_->right_ = nullptr;
				delete ptr;
			}

			if (ptr->left_ && !ptr->right_)
			{
				if (ptr->p_->left_ && ptr->p_->left_->key_ == key) ptr->p_->left_ = ptr->left_;
				else if (ptr->p_->right_ && ptr->p_->right_->key_ == key) ptr->p_->right_ = ptr->left_;
				ptr->left_->p_ = ptr->p_;
				delete ptr;
			}

			if (!ptr->left_ && ptr->right_)
			{
				if (ptr->p_->left_ && ptr->p_->left_->key_ == key) ptr->p_->left_ = ptr->right_;
				else if (ptr->p_->right_ && ptr->p_->right_->key_ == key) ptr->p_->right_ = ptr->right_;
				ptr->right_->p_ = ptr->p_;
				delete ptr;
			}
			
			if (ptr->left_ && ptr->right_)
			{
				Node<T>* min = ptr->right_;
				while (min->left_) min = min->left_;
				if (min->p_->left_ && min->p_->left_->key_ == min->key_) min->p_->left_ = nullptr;
				else if (min->p_->right_ && min->p_->right_->key_ == min->key_) min->p_->right_ = nullptr;
				ptr->key_ = min->key_;
				delete min;
			}

			
			return true;
		}
		
	}

	int getNumberOfNodes() const { return getNumberOfNodes(root); }
	int getHeight() const { return getHeight(root); }
	
	void inorderWalkIterative() const
	{
		if (root)
		{
			Stack<Node<T>*> stack;
			Node<T>* ptr = root;
			while (ptr || !stack.isEmpty())
			{
				while (ptr)
				{
					stack.push(ptr);
					ptr = ptr->left_;
				}
				ptr = stack.getTop();
				stack.pop();
				std::cout << ptr->key_ << " ";
				ptr = ptr->right_;
			}
			std::cout << "\n";
		}
		else std::cerr << EMPTY_COLLECTION;
	}
	void inorderWalk() const 
	{
		if (!root) std::cerr << EMPTY_COLLECTION;
		else
		{
			inorderWalk(root);
			std::cout << "\n";
		}
	}
	void walkByLevels() const
	{
		if (root)
		{
			Queue<Node<T>*> queue;
			queue.push(root);
			Node<T>* ptr = nullptr;
			while (!queue.isEmpty())
			{
				ptr = queue.getFront();
				std::cout << ptr->key_ << " ";
				queue.pop();
				if (ptr->left_) queue.push(ptr->left_);
				if (ptr->right_) queue.push(ptr->right_);
			}
			std::cout <<"\n";
		}
		else std::cerr << EMPTY_COLLECTION;
		
	}
	bool isSimilar(const BinarySearchTree<T>& other) const
	{
		std::ostringstream ostr1;
		inorderWalk(ostr1, root);
		std::ostringstream ostr2;
		inorderWalk(ostr2, other.root);
		return ostr1.str() == ostr2.str() ? true : false;
	}
	bool isIdenticalKey(const BinarySearchTree<T>& other) const
	{
		std::ostringstream ostr1;
		inorderWalk(ostr1, root);
		std::ostringstream ostr2;
		inorderWalk(ostr2, other.root);
		for (char key2 : ostr2.str())
			for (char key1 : ostr1.str())
				if (key1 == key2) return true;
		return false;
	}

private:
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
	Node<T> *root;

	Node<T>* searchNodeIterative(const T& key) const
	{
		if (!root) return nullptr;
		else
		{
			Node<T>* ptr = root;
			while (ptr && ptr->key_ != key)
			{
				if (key < ptr->key_) ptr = ptr->left_;
				else ptr = ptr->right_;
			}
			return ptr;
		}
	}
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
	int getNumberOfNodes(const Node<T>* node) const
	{
		if (!node) return 0;
		else return 1 + getNumberOfNodes(node->right_) + getNumberOfNodes(node->left_);

	}
	int getHeight(const Node<T>* node) const
	{
		if (!node) return 0;
		else return 1 + std::max(getHeight(node->left_), getHeight(node->right_));
	}
	void inorderWalk(Node<T>* node) const
	{
		if (!node) return;
		else
		{
			inorderWalk(node->left_);
			std::cout << node->key_ << " ";
			inorderWalk(node->right_);
		}
	}
	void inorderWalk(std::ostringstream &oss,Node<T>* node) const
	{
		if (!node) return;
		else
		{
			inorderWalk(oss,node->left_);
			oss<<node->key_<<" ";
			inorderWalk(oss,node->right_);
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
};

#endif 