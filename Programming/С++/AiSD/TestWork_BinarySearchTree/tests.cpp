#include "BinarySearchTree.hpp"

void test()
{
	BinarySearchTree<int> tree;
	for(std::size_t i = 0; i <= 10; i++)
	{
		int x = rand() % 100;
		tree.insertNode(x);
	}
	std::cout << "Determining the maximum key of leaf nodes of a tree using a recursive method: " << tree.findMaxLeafKeyRecursive() << std::endl;
	std::cout << "Determining the maximum key of leaf nodes of a tree using a iterative method: " << tree.findMaxLeafKeyIterative() << std::endl;
}