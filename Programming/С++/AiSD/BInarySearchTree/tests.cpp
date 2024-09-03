#include "BinarySearchTree.hpp"

void test()
{
    BinarySearchTree<int> tree, similarTree;
	for (size_t i = 0; i < 10; ++i) {
		int x = rand() % 100;
		similarTree.insertNode(x);
		std::cout << "insert " << x << ": " << tree.insertNode(x) << ' ';
		tree.output(std::cout);
		std::cout << std::endl;
	}
	std::cout << std::endl << "Height: " << tree.getHeight() << std::endl;
	std::cout << "Number of nodes: " << tree.getNumberOfNodes() << std::endl;
	std::cout << "Search 35: " << tree.searchKeyIterative(35) << std::endl;
	std::cout << "Delete 35: " << tree.deleteNode(35) << std::endl;
	std::cout << "Search 35: " << tree.searchKeyIterative(35) << std::endl;

	std::cout << std::endl << "inorderWalkIterative:\t";
	tree.inorderWalkIterative();
	std::cout << std::endl;

	std::cout << "inorderWalk:\t";
	tree.inorderWalk();
	std::cout << std::endl;

	std::cout << "walkByLevels:\t";
	tree.walkByLevels();
	std::cout << std::endl << std::endl;


	std::cout << "tree: ";
	tree.output(std::cout);
	std::cout << std::endl << "similarTree: ";
	similarTree.output(std::cout);
	std::cout << std::endl << "tree.isSimilar(similarTree): " << tree.isSimilar(similarTree) << std::endl;
	std::cout << "tree.isIdenticalKey(similarTree): " << tree.isIdenticalKey(similarTree) << std::endl;
}