#include "Structs.h"

AVL_Tree::~AVL_Tree() { deleteNodes(root); }

void AVL_Tree::deleteNodes(Node* node)
{
	if (!node) return;
	else
	{
		deleteNodes(node->left_);
		deleteNodes(node->right_);
		delete node;
	}
}

void AVL_Tree::search(const std::string& word)const
{
	if (!root) throw std::runtime_error(ERROR_IS_EMPTY_TREE);
	else
		if (!searchIterative(word)) std::cout << word <<" is not found in vocabulary\n";
		else std::cout << word << " :  " << searchIterative(word)->cnt_<<"\n";
}

AVL_Tree::Node* AVL_Tree::searchIterative(const std::string& word)const
{
	if (!root) return nullptr;
	else
	{
		Node* ptr = root;
		while (ptr && ptr->key_!=word)
		{
			if (ptr->key_ > word) ptr = ptr->left_;
			else ptr = ptr->right_;
		}
		return ptr;
	}
}

int AVL_Tree::getHightOfSubTree(Node* node)const
{
	if (!node) return 0;
	else return 1 + std::max(getHightOfSubTree(node->left_), getHightOfSubTree(node->right_));
}

void AVL_Tree::setBalance(Node*& node)const
{
	node->balance_ = getHightOfSubTree(node->right_) - getHightOfSubTree(node->left_);
}

void AVL_Tree::turnLeft(Node*& node)
{
	Node* rightSubTree = node->right_;
	Node* rightSubTreeLeftSubTree = rightSubTree->left_;

	rightSubTree->left_ = node;
	node->right_ = rightSubTreeLeftSubTree;
	node = rightSubTree;
	setBalance(node->left_);
	setBalance(node);
}

void AVL_Tree::turnRigth(Node*& node)
{
	Node* leftSubTree = node->left_;
	Node* leftSubTreeRightSubTree = leftSubTree->right_;

	leftSubTree->right_ = node;
	node->left_ = leftSubTreeRightSubTree;
	node = leftSubTree;
	setBalance(node->right_);
	setBalance(node);
}

void AVL_Tree::insert(const std::string& word) { insretRecoursive(root, word); }

void AVL_Tree::insretRecoursive(Node*& node,const std::string& word)
{
	if (!node)
		node = new Node(word);
	else
	{
		if (searchIterative(word)) searchIterative(word)->cnt_++;
		else
		{
			if (node->key_ < word)
			{
				insretRecoursive(node->right_, word);
				if (getHightOfSubTree(node->right_) - getHightOfSubTree(node->left_) > 1)
				{
					if (getHightOfSubTree(node->right_->right_) < getHightOfSubTree(node->right_->left_))
						turnRigth(node->right_);
					turnLeft(node);
				}
			}
			else
			{
				insretRecoursive(node->left_, word);
				if (getHightOfSubTree(node->left_) - getHightOfSubTree(node->right_) > 1)
				{
					if (getHightOfSubTree(node->left_->left_) < getHightOfSubTree(node->left_->right_))
						turnLeft(node->left_);
					turnRigth(node);
				}
			}
			setBalance(node);
		}
	}
}

void AVL_Tree::remove(const std::string& word)
{
	if (!root) throw std::runtime_error(ERROR_IS_EMPTY_TREE);
	if (!searchIterative(word)) std::cerr << word << " is not found\n";
	else
	{
		removeRecoursive(root, word);
		if (root)  setBalanceAfterRemove(root);
	}
}

void AVL_Tree::removeRecoursive(Node*& node,const  std::string& word) const
{
	if (!node) return;
	else
	{
		if (node->key_ < word) removeRecoursive(node->right_, word);
		else
			if (node->key_ > word) removeRecoursive(node->left_, word);
			else
			{
				if (!node->left_ && !node->right_)
				{
					delete node;
					node = nullptr;
				}
				else if (!node->right_)
				{
					Node* ptr = node;
					node = node->left_;
					delete ptr;
				}
				else if (!node->left_)
				{
					Node* ptr = node;
					node = node->right_;
					delete ptr;
				}
				else
				{
					Node* minNode = node->right_;
					while (minNode->left_) minNode = minNode->left_;
					node->key_ = minNode->key_;
					removeRecoursive(node->right_, minNode->key_);
				}
			}
		if (node)setBalance(node);
	}
}


void AVL_Tree::setBalanceAfterRemove(Node* node)
{
	Stack stack;
	Node* ptr = root;
	while (node->key_!= ptr->key_)
	{
		stack.push(ptr);
		if (ptr->key_ < node->key_) ptr = ptr->right_;
		else ptr = ptr->left_;
	}
	while (ptr)
	{
		Node* change = nullptr;
		if (abs(ptr->balance_) > 1) 
		{
			if (ptr->balance_ > 1)
			{
				if (ptr == root) turnLeft(root);
				else
				{
					turnLeft(ptr);
					change = ptr;
				}
			}
			else
			{
				if (ptr == root) turnRigth(root);
				else
				{
					turnRigth(ptr);
					change = ptr;
				}
			}
		}
		if (stack.isEmpty()) break;
		else 
		{
			ptr = stack.getTop();
			if (change && ptr->key_ > change->key_ && ptr->left_ != change) ptr->left_ = change;
			if(change && ptr->key_ < change->key_ && ptr->right_ != change) ptr->right_ = change;
			setBalance(ptr);
			stack.pop();
		}
	}
	if (node->right_)setBalanceAfterRemove(node->right_);
	if (node->left_)setBalanceAfterRemove(node->left_);
}


int AVL_Tree::countOfNodes(Node* node)const
{
	if (!node) return 0;
	return countOfNodes(node->right_) + countOfNodes(node->left_) + 1;
}

void AVL_Tree::outputRecoursive( Node*& node, int level) const
{
	if (!node) return;
	else
	{
		if (level == 1)
			std::cout << node->key_ <<"("<<node->cnt_<<","<<node->balance_<< ") ";
		else if (level > 1)
		{
			outputRecoursive(node->left_, level - 1);
			outputRecoursive(node->right_, level - 1);
		}
	}
}

void AVL_Tree::output()
{
	if (!root) std::cerr << ERROR_IS_EMPTY_TREE << "\n";
	else
	{
		int height = getHightOfSubTree(root) + 1;
		for (int level = 1; level <= height; level++)
		{
			outputRecoursive(root, level);
			std::cout << std::endl;
		}
	}
}
void AVL_Tree::findMax()
{
	if (countOfNodes(root) < 3) throw std::runtime_error(ERROR_IN_THE_NUMBER_OF_ELEMENTS);
	Node* arr[SIZE]{ nullptr };
	findMaxRecoursive(root, arr);
	std::cout << "3 most common words:\n";
	for (auto el : arr)
		std::cout << el->key_ << ": " << el->cnt_ << "\n";
}
void AVL_Tree::findMaxRecoursive(Node* node, Node* arr[SIZE])const
{
	if (!node) return;
	else
	{
		if (!arr[0]) arr[0] = node;
		else
			if (arr[0]->cnt_ <= node->cnt_)
			{
				for (int i = SIZE - 1; i > 0; --i)
					arr[i] = arr[i - 1];
				arr[0] = node;
			}
		findMaxRecoursive(node->right_, arr);
		findMaxRecoursive(node->left_, arr);
	}
}