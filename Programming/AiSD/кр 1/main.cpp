#include"DoubleLinkedList.h"
#include<string>

int main()
{
	setlocale(LC_ALL, "ru");
		std::cout << "___________________int______________\n";
		DoubleLinkedList<int> list1;
		list1.print();
		list1.reverce();
		list1.insert(1);
		list1.insert(2);
		list1.insert(3);
		list1.insert(4);
		std::cout << "List:\t";
		list1.print();
		list1.reverce();
		std::cout << "отсортированнный List:\t";
		list1.print();

		std::cout << "\n___________________char______________\n";
		DoubleLinkedList<char> list2;
		list2.print();
		list2.reverce();
		list2.insert('a');
		list2.insert('b');
		list2.insert('c');
		list2.insert('d');
		std::cout << "List:\t";
		list2.print();
		list2.reverce();
		std::cout << "отсортированнный List:\t";
		list2.print();

		std::cout << "\n___________________string______________\n";
		DoubleLinkedList<std::string> list3;
		list3.print();
		list3.reverce();
		list3.insert("apple");
		list3.insert("banana");
		list3.insert("cat");
		list3.insert("dog");
		std::cout << "List:\t";
		list3.print();
		list3.reverce();
		std::cout << "отсортированнный List:\t";
		list3.print();
	return 0;
}