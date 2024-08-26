#include"Tree.h"

int main()
{
  setlocale(LC_ALL, "ru");
  try {
    BinarySearchTree<int> tr;
    tr.insertNode(4);
    tr.insertNode(7);
    tr.insertNode(3);
    tr.insertNode(12);
    tr.insertNode(5);
    tr.output(std::cout);
    std::cout << "Минимальное значение узлов-листьев (циклы):  " << tr.findMinLeafKey() << std::endl;
    std::cout << "Минимальное значение узлов-листьев (рекурсия):  " << tr.findMinLeafKeyRecursive() << std::endl;
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what();
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

