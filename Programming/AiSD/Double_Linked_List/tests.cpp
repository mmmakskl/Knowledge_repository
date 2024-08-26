#include "doubleLinkedList.hpp"

void test()
{
    std::cout << "Make and test list 'list'" << std::endl;
    {
        doubleLinkedList<int> list;
        list.insertHead(24);
        list.insertHead(3);
        list.insertHead(9);
        list.insertHead(9);
        list.insertTail(5);
        list.insertTail(7);
        list.insertTail(9);
        list.insertHead(6);
        list.insertHead(8);
        list.insertTail(2);
        std::cout << "list: " << list;
        std::cout << "Test of the deleteLess function on the 'list' list" << std::endl;
        list.deleteLess();
        std::cout << "list: " << list;
    }
    std::cout << "Make and test empty list 'empty'" << std::endl;
    {
        doubleLinkedList<int> empty;
        std::cout << "empty: " << empty;
        std::cout << "Test of the deleteLess function on the 'empty' list" << std::endl;
        empty.deleteLess();
        std::cout << "empty: " << empty;
    }
    return;
}