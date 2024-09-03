#pragma once
#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include "Queue.hpp"
#include "Stack.hpp"

void test();

template <typename T>
class BinarySearchTree
{
private:
    template <typename U>
    struct Node
    {
        U key_;
        Node<U>* left_;
        Node<U>* right_;
        Node<U>* p_;

        Node(U key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
            key_(key),
            left_(left),
            right_(right),
            p_(p)
        {}
    };
    Node<T>* root_;
    bool insertNode(Node<T>* node, const T& key);
    void makeEmpty(Node<T>* root) const;
    BinarySearchTree<T>::Node<T>* searchNodeIterative(const T& key) const;
    void output(std::ostream &out, Node<T>* node) const;
    std::size_t getNumberOfNodes(const Node<T>* node) const;
    std::size_t getHeight(const Node<T>* node) const;
    void inorderWalk(Node<T>* node) const;
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<T> & scr) = delete;
    BinarySearchTree(BinarySearchTree<T>&& scr) noexcept;
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>&& src) = delete;
    BinarySearchTree<T>& operator=(BinarySearchTree <T>&& src) noexcept;
    virtual ~BinarySearchTree();

    bool searchKeyIterative (const T& key) const;
    bool insertNode(const T& key);
    bool deleteNode(const T& key);
    void output(std::ostream& out) const;
    std::size_t getNumberOfNodes() const;
    std::size_t getHeight() const;
    void inorderWalkIterative() const;
    void inorderWalk() const;
    void walkByLevels() const;
    bool isSimilar(const BinarySearchTree<T> & other) const;
    bool isIdenticalKey(const BinarySearchTree<T> & other) const;
};

template <typename T>
bool BinarySearchTree<T>::insertNode(Node<T> *node, const T &key)
{
    if(searchKeyIterative(key))
    {
        return false;
    }
    if(key < node->key_)
    {
        if(!node->left_)
        {
            node->left_ = new Node<T>(key, nullptr, nullptr, node);
            return true;
        }
        return insertNode(node->left_, key);
    }
    else
    {
        if(!node->right_)
        {
            node->right_ = new Node<T>(key, nullptr, nullptr, node);
            return true;
        }
        return insertNode(node->right_, key);
    }
}

template <typename T>
void BinarySearchTree<T>::makeEmpty(Node<T> *node) const
{
    if(node)
    {
        makeEmpty(node->left_);
        makeEmpty(node->right_);
        delete node;
    }
}

template <typename T>
BinarySearchTree<T>::Node<T> *BinarySearchTree<T>::searchNodeIterative(const T &key) const
{
    Node<T> *current = root_;
    while (current)
    {
        if(current->key_ == key)
            break;
        else if (key < current->key_)
        {
            current = current->left_;
        }
        else
        {
            current = current->right_;
        }
    }
    return current;
}

template <typename T>
void BinarySearchTree<T>::output(std::ostream &out, Node<T> *root) const
{
    if (root)
    {
        out << "(";
        output(out, root->left_);
        out << root->key_;
        output(out, root->right_);
        out << ")";
    }
}

template <typename T>
std::size_t BinarySearchTree<T>::getNumberOfNodes(const Node<T> *node) const
{
    if(node == nullptr)
    {
        return 0;
    }
    return(1 + getNumberOfNodes(node->left_) + getNumberOfNodes(node->right_));
}

template <typename T>
std::size_t BinarySearchTree<T>::getHeight(const Node<T> *node) const
{
    if(node == nullptr || node->left_ == nullptr && node->right_ == nullptr)
        return 0;
    return (std::max(getHeight(node->left_), getHeight(node->right_)) + 1);
}

template <typename T>
void BinarySearchTree<T>::inorderWalk(Node<T> *node) const
{
    if(node)
    {
        if (node->left_)
            inorderWalk(node->left_);
        std::cout << node->key_ << " ";
        if (node->right_)
            inorderWalk(node->right_);
    }
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr)
{}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> && scr) noexcept :
    root_(scr.root_)
{
    scr.root_ = nullptr;
}

template <typename T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(BinarySearchTree<T> &&src) noexcept
{
    root_ = src.root_;
    src.root_ = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    makeEmpty(root_);
}

template <typename T>
inline bool BinarySearchTree<T>::searchKeyIterative(const T &key) const
{
    return (searchNodeIterative(key) != nullptr);
}

template <typename T>
bool BinarySearchTree<T>::insertNode(const T &key)
{
    if(!root_)
    {
        root_ = new Node<T>(key);
        return true;
    }
    return insertNode(root_, key);
}

template <typename T>
bool BinarySearchTree<T>::deleteNode(const T &key)
{
    Node<T>** current = &root_;
    if(!searchKeyIterative(key))
        return false;

	while (*current && (*current)->key_ != key) 
    {
		if ((*current)->key_ < key)
			current = &(*current)->right_;
		else
			current = &(*current)->left_;
	}

    Node<T>** tmp = &(*current)->right_;

    while (*tmp)
        tmp =&(*tmp)->left_;

    Node<T>* del = *current;
    *tmp = del->left_;
    *current = del->right_;
    delete del;

    return true;
}

template <typename T>
void BinarySearchTree<T>::output(std::ostream &out) const
{
    output(out, root_);
}

template <typename T>
std::size_t BinarySearchTree<T>::getNumberOfNodes() const
{
    return getNumberOfNodes(root_);
}

template <typename T>
inline std::size_t BinarySearchTree<T>::getHeight() const
{
    return getHeight(root_);
}

template <typename T>
void BinarySearchTree<T>::inorderWalkIterative() const
{
    StackArray<Node<T>*> stack;
    Node<T>* top = root_;
    while (top || !stack.isEmpty())
    {
        if(top)
        {
			stack.push(top);
			top = top->left_;
        }
        else
        {
            top = stack.top();
            stack.pop();
            std::cout<< top->key_ << " ";
            top = top->right_;
        }
    }
}

template <typename T>
void BinarySearchTree<T>::inorderWalk() const
{
    return inorderWalk(root_);
}

template <typename T>
void BinarySearchTree<T>::walkByLevels() const
{
    QueueArray<Node<T>*> queue;
    queue.enQueue(root_);
    while (!queue.isEmpty())
    {
        Node<T>* top = queue.deQueue();
        std::cout << top->key_ << " ";
        if (top->left_)
            queue.enQueue(top->left_);
        if (top->right_)
            queue.enQueue(top->right_);
    }
}

template <typename T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T> &other) const
{
    StackArray<Node<T>*> stack1, stack2;
    Node<T>* ptr1 = root_, *ptr2 = other.root_;
    bool flag = true;
    T lastValue;

    while (ptr1 || !stack1.isEmpty() || ptr2 || !stack2.isEmpty())
    {
        if(!ptr2 && stack2.isEmpty())
            return false;
		Node<T> *&ptr = flag ? ptr1 : ptr2;
		StackArray<Node<T> *> &stack = flag ? stack1 : stack2;
        if(ptr)
        {
            stack.push(ptr);
            ptr = ptr->left_;
        }
        else
        {
            ptr = stack.top();
            stack.pop();
            if(flag)
                lastValue = ptr->key_;
            else if (lastValue != ptr->key_)
                return false;
            ptr = ptr->right_;
            flag = !flag;
        }
    }
    return true;
}

template <typename T>
bool BinarySearchTree<T>::isIdenticalKey(const BinarySearchTree<T> &other) const
{
    StackArray<Node<T>*> stack1, stack2;
    Node<T>* ptr1 = root_, *ptr2 = other.root_;
    bool flag = true;
    Node<T>* value1 = nullptr, *value2 = nullptr;

    while (ptr1 || !stack1.isEmpty() || ptr2 || !stack2.isEmpty())
    {
        if(flag && !ptr1 && stack1.isEmpty() || !flag && !ptr2 && stack2.isEmpty())
            return false;
        Node<T>*& ptr = flag ? ptr1 : ptr2;
        StackArray<Node<T>*>& stack = flag ? stack1 : stack2;

        if(ptr != nullptr)
        {
            stack.push(ptr);
            ptr = ptr->left_;
        }
        else
        {
            ptr = stack.top();
            stack.pop();

            if(flag)
                value1 = ptr;
            else
                value2 = ptr;

            ptr = ptr->right_;
            if(value1 && value2)
            {
                if (value1->key_ == value2->key_)
                    return true;
                flag = value1->key_ < value2->key_;
            }
            else
                flag = false;
        }
    }
    return false;
}

#endif
