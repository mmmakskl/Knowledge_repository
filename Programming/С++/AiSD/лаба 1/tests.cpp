#include "tests.h"

void testWithChar()
{

    DictionaryList<char> list1;
    DictionaryList<char> list2;
    std::cout << "�������� ��������:\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.insert('c');
    list1.insert('d');
    list1.insert('c');
    list1.insert('v');
    std::cout << "\n���������� ��������:\n\tlist1:  ";
    list1.print();
    list2.insert('e');
    list2.insert('d');;
    list2.insert('a');
    list2.insert('f');
    std::cout << "\tlist2:  ";
    list2.print();
    std::cout << "\n����� 'v' � list1:\t";
    list1.search('v') ? std::cout << "������� � �������\n" : std::cout << "������� �� ���������� � �������\n";
    list1.remove('v');
    std::cout << "\n�������� 'v' �� list1:\t";
    list1.print();
    std::cout << "�������� 't' �� list1:\t";
    list1.remove('t');
    std::cout << "\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    auto list3 = list1.getIntersection(list2);
    std::cout << "\n����������� list1 � list2:\t";
    list3->print();
    list1.deleteWords(list2);
    std::cout << "\n�������� �� list1 ���������, ����������� � list2\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.merge(list2);
    std::cout << "\n����������� list2 -> list1\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    delete list3;
}

void testWithNumbers()
{
    DictionaryList<int> list1;
    DictionaryList<int> list2;
    std::cout << "�������� ��������:\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.insert(5);
    list1.insert(2);
    list1.insert(43);
    list1.insert(4);
    std::cout << "\n���������� ��������:\n\tlist1:  ";
    list1.print();
    list2.insert(15);
    list2.insert(7);;
    list2.insert(5);
    list2.insert(4);
    std::cout << "\tlist2:  ";
    list2.print();
    std::cout << "\n����� '5' � list1:\t";
    list1.search(5) ? std::cout << "������� � �������\n" : std::cout << "������� �� ���������� � �������\n";
    list1.remove(5);
    std::cout << "\n�������� '5' �� list1:\t";
    list1.print();
    std::cout << "�������� '100' �� list1:\t";
    list1.remove(100);
    std::cout << "\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    auto list3 = list1.getIntersection(list2);
    std::cout << "\n����������� list1 � list2:\t";
    list3->print();
    list1.deleteWords(list2);
    std::cout << "\n�������� �� list1 ���������, ����������� � list2\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.merge(list2);
    std::cout << "\n����������� list2 -> list1\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    delete list3;
}

void testWithString()
{
    DictionaryList<std::string> list1;
    DictionaryList<std::string> list2;
    std::cout << "�������� ��������:\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.insert("dog");
    list1.insert("apple");
    std::cout << "\n���������� ��������:\n\tlist1:  ";
    list1.print();
    list2.insert("dog");
    list2.insert("cat");
    std::cout << "\tlist2:  ";
    list2.print();
    std::cout << "\n����� 'cat' � list1:\t";
    list1.search("cat") ? std::cout << "������� � �������\n" : std::cout << "������� �� ���������� � �������\n";
    list1.remove("dog");
    std::cout << "\n�������� 'dog' �� list1:\t";
    list1.print();
    std::cout << "�������� 'cat' �� list1:\t";
    list1.remove("cat");
    std::cout << "\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    auto list3 = list1.getIntersection(list2);
    std::cout << "\n����������� list1 � list2:\t";
    list3->print();
    list1.deleteWords(list2);
    std::cout << "\n�������� �� list1 ���������, ����������� � list2\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.merge(list2);
    std::cout << "\n����������� list2 -> list1\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    delete list3;
}

