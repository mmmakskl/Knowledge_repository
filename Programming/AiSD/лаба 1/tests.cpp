#include "tests.h"

void testWithChar()
{

    DictionaryList<char> list1;
    DictionaryList<char> list2;
    std::cout << "Создание словарей:\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.insert('c');
    list1.insert('d');
    list1.insert('c');
    list1.insert('v');
    std::cout << "\nЗаполнение словарей:\n\tlist1:  ";
    list1.print();
    list2.insert('e');
    list2.insert('d');;
    list2.insert('a');
    list2.insert('f');
    std::cout << "\tlist2:  ";
    list2.print();
    std::cout << "\nПоиск 'v' в list1:\t";
    list1.search('v') ? std::cout << "Элемент в словаре\n" : std::cout << "Элемент не содержится в словаре\n";
    list1.remove('v');
    std::cout << "\nУдаление 'v' из list1:\t";
    list1.print();
    std::cout << "Удаление 't' из list1:\t";
    list1.remove('t');
    std::cout << "\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    auto list3 = list1.getIntersection(list2);
    std::cout << "\nПересечение list1 и list2:\t";
    list3->print();
    list1.deleteWords(list2);
    std::cout << "\nУдаление из list1 элементов, совпадающих с list2\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.merge(list2);
    std::cout << "\nПеремещение list2 -> list1\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    delete list3;
}

void testWithNumbers()
{
    DictionaryList<int> list1;
    DictionaryList<int> list2;
    std::cout << "Создание словарей:\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.insert(5);
    list1.insert(2);
    list1.insert(43);
    list1.insert(4);
    std::cout << "\nЗаполнение словарей:\n\tlist1:  ";
    list1.print();
    list2.insert(15);
    list2.insert(7);;
    list2.insert(5);
    list2.insert(4);
    std::cout << "\tlist2:  ";
    list2.print();
    std::cout << "\nПоиск '5' в list1:\t";
    list1.search(5) ? std::cout << "Элемент в словаре\n" : std::cout << "Элемент не содержится в словаре\n";
    list1.remove(5);
    std::cout << "\nУдаление '5' из list1:\t";
    list1.print();
    std::cout << "Удаление '100' из list1:\t";
    list1.remove(100);
    std::cout << "\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    auto list3 = list1.getIntersection(list2);
    std::cout << "\nПересечение list1 и list2:\t";
    list3->print();
    list1.deleteWords(list2);
    std::cout << "\nУдаление из list1 элементов, совпадающих с list2\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.merge(list2);
    std::cout << "\nПеремещение list2 -> list1\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    delete list3;
}

void testWithString()
{
    DictionaryList<std::string> list1;
    DictionaryList<std::string> list2;
    std::cout << "Создание словарей:\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.insert("dog");
    list1.insert("apple");
    std::cout << "\nЗаполнение словарей:\n\tlist1:  ";
    list1.print();
    list2.insert("dog");
    list2.insert("cat");
    std::cout << "\tlist2:  ";
    list2.print();
    std::cout << "\nПоиск 'cat' в list1:\t";
    list1.search("cat") ? std::cout << "Элемент в словаре\n" : std::cout << "Элемент не содержится в словаре\n";
    list1.remove("dog");
    std::cout << "\nУдаление 'dog' из list1:\t";
    list1.print();
    std::cout << "Удаление 'cat' из list1:\t";
    list1.remove("cat");
    std::cout << "\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    auto list3 = list1.getIntersection(list2);
    std::cout << "\nПересечение list1 и list2:\t";
    list3->print();
    list1.deleteWords(list2);
    std::cout << "\nУдаление из list1 элементов, совпадающих с list2\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    list1.merge(list2);
    std::cout << "\nПеремещение list2 -> list1\n\tlist1:  ";
    list1.print();
    std::cout << "\tlist2:  ";
    list2.print();
    delete list3;
}

