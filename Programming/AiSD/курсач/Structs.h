#ifndef AVL_TREE_H
#define AVL_TREE_H

#include<iostream>
#include<string>

const int SIZE = 3;
const std::string ERROR_IS_EMPTY_TREE = "Vocabulary is empty\n";
const std::string ERROR_IN_THE_NUMBER_OF_ELEMENTS = "The number of elements is less than 3\n";
const std::string ERROR_STACK_UNDERFLOW = "Srack underflow\n";

class AVL_Tree
{
	friend class Stack;
	struct Node
	{
		Node(std::string key) :
			key_(key), cnt_(1), balance_(0), right_(nullptr), left_(nullptr) {};

		std::string key_;
		int cnt_;
		int balance_;
		Node* right_;
		Node* left_;
	};

public:
	AVL_Tree() : root(nullptr) {};
	~AVL_Tree();
	void search(const std::string& word) const;
	void insert(const std::string& word);  
	void remove(const std::string& word);
	void output();
	void findMax();

private:
	Node* root;
	void deleteNodes(Node* node);
	Node* searchIterative(const std::string& word)const;
	int getHightOfSubTree(Node* node)const;
	void setBalance(Node*& node)const;
	void turnLeft(Node*& node);
	void turnRigth(Node*& node);
	void insretRecoursive(Node*& node, const std::string& word);
	void removeRecoursive(Node*& node, const std::string& word)const;
	void setBalanceAfterRemove(Node* node);
	void outputRecoursive(Node*& node, int level)const;
	int countOfNodes(Node* node)const;
	void findMaxRecoursive(Node* node, Node* arr[SIZE])const;
};


class Stack
{
	struct NodeStack
	{
		AVL_Tree::Node* key_;
		NodeStack* next_;
		NodeStack(AVL_Tree::Node* key, NodeStack* next = nullptr) : key_(key), next_(next) {};
	};
public:
	Stack() : top(nullptr) {};
	~Stack();
	bool isEmpty() const;
	void push(AVL_Tree::Node* key);
	AVL_Tree::Node* getTop() const;
	void pop();

private:
	NodeStack* top;
};

#endif
