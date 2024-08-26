#pragma once
#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include "Queue.hpp"
#include "Stack.hpp"
#include <limits>

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
    T findMaxLeafKeyRecursive(Node<T>* node);
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
    void inorderWalk() const;

    T findMaxLeafKeyRecursive();
    T findMaxLeafKeyIterative();
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
void BinarySearchTree<T>::inorderWalk() const
{
    return inorderWalk(root_);
}

template <typename T>
inline T BinarySearchTree<T>::findMaxLeafKeyRecursive(Node<T> *node)
{
    if(node == nullptr)
        throw "Tree is empty";
    if(node->left_ == nullptr && node->right_ == nullptr)
        return node->key_;
    T leftMax = std::numeric_limits<T>::min();
    T rightMax = std::numeric_limits<T>::min();
    if(node->left_)
        leftMax = findMaxLeafKeyRecursive(node->left_);
    if(node->right_)
        rightMax = findMaxLeafKeyRecursive(node->right_);

    return std::max(leftMax, rightMax);
}

template <typename T>
inline T BinarySearchTree<T>::findMaxLeafKeyRecursive()
{
    return findMaxLeafKeyRecursive(root_);
}

template <typename T>
inline T BinarySearchTree<T>::findMaxLeafKeyIterative()
{
    if(root_ == nullptr)
    {
        throw "Tree is empty";
    }
    StackArray<Node<T>*> stack;
    stack.push(root_);
    T max_key = std::numeric_limits<T>::min();;
    while (!stack.isEmpty())
    {
        Node<T>* current = stack.top();
        stack.pop();
        if (current->left_ == nullptr && current->right_ == nullptr)
        {
            if (current->key_ > max_key)
            {
                max_key = current->key_;
            }
        }
        if(current->right_ != nullptr)
            stack.push(current->right_);
        if(current->left_ != nullptr)
            stack.push(current->left_);
    }
    return max_key;
}

#endif
