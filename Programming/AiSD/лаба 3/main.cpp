#include <iostream>
#include"BinarySearchTree.h"

int main()
{
    setlocale(LC_ALL , "ru");
    std::cout << "_______________ BinarySearchTree<int>__________________\n\n";
    BinarySearchTree<int> tr;
    tr.output(std::cout);
    tr.insertNode(5);
    tr.insertNode(3);
    tr.insertNode(8);
    tr.insertNode(1);
    tr.insertNode(4);
    tr.insertNode(12);
    tr.output(std::cout);
    tr.searchKeyIterative(10) ? std::cout << "Элемент в коллекции\n" : std::cout << "Элемент отсутствует\n";
    if (tr.deleteNode(3))
    {
        std::cout << "Элемент 3 удален:\t";
        tr.output(std::cout);
    }
    else std::cout << "Элемент отсутствует\n";
    std::cout << tr.getNumberOfNodes() << "\tузлов\n";
    std::cout << "Высота дерева:\t" << tr.getHeight()<<"\n";
    std::cout << "Инфиксный обход дерева(итеративный):  ";
    tr.inorderWalkIterative();
    std::cout << "Инфиксный обход дерева(рекурсивный):  ";
    tr.inorderWalk();
    std::cout << "Обход дерева в ширину:  ";
    tr.walkByLevels();
    BinarySearchTree<int> tr1 ;
    tr1.insertNode(rand()%30);
    tr1.insertNode(rand() % 30);
    tr1.insertNode(rand() % 30);
    tr1.insertNode(rand() % 30);
    tr1.insertNode(rand() % 30);
    std::cout << "\n\nСтарое дерево:\t";
    tr.output(std::cout);
    std::cout << "Новое дерево:\t";
    tr1.output(std::cout);
    tr.isSimilar(tr1)? std::cout << "Деревья совпадают\n":std::cout << "Деревья не совпадают\n";
    tr.isIdenticalKey(tr1)? std::cout << "Есть одинаковые ключи\n" : std::cout << "Одинаковые ключи отсутсвуют\n";

    return EXIT_SUCCESS;
}

