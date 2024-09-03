#include "dictionaryList.hpp"

void test()
{
    std::cout << "Creating and testing a list of int:" << std::endl << "========================================" << std::endl;
    {
        std::cout << "list creation increase 'list':" << std::endl;
        DictionaryList<int> list;
        list.increaseInsert(49);
        list.increaseInsert(3);
        list.increaseInsert(4);
        list.increaseInsert(6);
        list.increaseInsert(25);
        list.increaseInsert(1);
        list.increaseInsert(96); 
        std::cout << "list: " << list << std::endl;

        std::cout << "list creation increase and unique 'lst':" << std::endl;
        DictionaryList<int> lst;
        lst.increaseUniqueInsert(7);
        lst.increaseUniqueInsert(45);
        lst.increaseUniqueInsert(4);
        lst.increaseUniqueInsert(45);
        lst.increaseUniqueInsert(52);
        lst.increaseUniqueInsert(34);
        lst.increaseUniqueInsert(3);
        lst.increaseUniqueInsert(9);
        lst.increaseUniqueInsert(7);
        std::cout << "lst: " << lst << std::endl;


        std::cout << "empty list creation 'empty':" << std::endl;
        DictionaryList<int> empty;
        std::cout << "empty: " << empty << std::endl;
        empty.insert(6);
        empty.insert(1);
        empty.insert(9);
        empty.insert(45);
        empty.insert(93);
        empty.insert(2);

        std::cout << "Search for the word '3' and '7' in the 'list' dictionary:" << std::endl;
        std::cout << "'3': " << (list.search(3) ? "Yes" : "No") << std::endl;
        std::cout << "'7': " << (list.search(7) ? "Yes" : "No") << std::endl << std::endl;

        std::cout << "Remove the word '6' from the 'list' dictionary:" << std::endl;
        std::cout << "before: " << list << std::endl;
        list.remove(6);
        std::cout << "after: " << list << std::endl;

        std::cout << "Merging dictionaries with the 'merge' function:" << std::endl;
        list.merge(std::move(lst));
        std::cout << "lst: " << lst << std::endl;
        std::cout << "list: " << list << std::endl;

        std::cout << "Deleting words from the dictionary with the 'deleteWords' function:" << std::endl;
        list.deleteWords(empty);
        std::cout << "list: " << list << std::endl;

        DictionaryList<int> biba;
        biba.insert(7);
        biba.insert(45);
        biba.insert(4);
        biba.insert(34);
        biba.insert(3);
        biba.insert(9);
        std::cout << "Getting dictionary intersection via 'getIntersection' function:" << std::endl;
        DictionaryList<int> intersection = getIntersection(list, biba);
        std::cout << "intersection: " << intersection;
    }
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Creating and testing a list of string:" << std::endl << "========================================" << std::endl;
    {
        std::cout << "list creation increase 'fruit':" << std::endl;
        DictionaryList<std::string> fruit;
        fruit.increaseInsert("banana");
        fruit.increaseInsert("apricot");
        fruit.increaseInsert("guava");
        fruit.increaseInsert("kiwi");
        fruit.increaseInsert("apple");
        fruit.increaseInsert("car");
        fruit.increaseInsert("ford"); 
        fruit.increaseInsert("mango");
        std::cout << "fruit: " << fruit << std::endl;

        std::cout << "list creation increase and unique 'car':" << std::endl;
        DictionaryList<std::string> car;
        car.increaseUniqueInsert("ferrari");
        car.increaseUniqueInsert("lamborgini");
        car.increaseUniqueInsert("apple");
        car.increaseUniqueInsert("mercedes");
        car.increaseUniqueInsert("grape");
        car.increaseUniqueInsert("car");
        car.increaseUniqueInsert("lamborgini");
        car.increaseUniqueInsert("date");
        std::cout << "car: " << car << std::endl;

        std::cout << "empty list creation 'empty':" << std::endl;
        DictionaryList<std::string> empty;
        std::cout << "empty: " << empty << std::endl;
        empty.insert("mango");
        empty.insert("plum");
        empty.insert("apple");
        empty.insert("kiwi");
        empty.insert("date");
        empty.insert("bmw");

        std::cout << "Search for the word 'guava' and 'lemon' in the 'fruit' dictionary:" << std::endl;
        std::cout << "'guava': " << (fruit.search("guava") ? "Yes" : "No") << std::endl;
        std::cout << "'lemon': " << (fruit.search("lemon") ? "Yes" : "No") << std::endl << std::endl;

        std::cout << "Remove the word 'car' from the 'fruit' dictionary:" << std::endl;
        std::cout << "before: " << fruit << std::endl;
        fruit.remove("car");
        std::cout << "after: " << fruit << std::endl;


        std::cout << "Merging dictionaries with the 'merge' function:" << std::endl;
        fruit.merge(std::move(car));
        std::cout << "car: " << car << std::endl;
        std::cout << "fruit: " << fruit << std::endl;

        std::cout << "Deleting words from the dictionary with the 'deleteWords' function:" << std::endl;
        fruit.deleteWords(empty);
        std::cout << "fruit: " << fruit << std::endl;

        DictionaryList<std::string> biba;
        biba.insert("fig");
        biba.insert("ford");
        biba.insert("banana");
        biba.insert("lime");
        biba.insert("ferrari");
        biba.insert("car");
        std::cout << "Getting dictionary intersection via 'getIntersection' function:" << std::endl;
        DictionaryList<std::string> intersection = getIntersection(fruit, biba);
        std::cout << "intersection: " << intersection;
    }
    std::cout << "========================================" << std::endl;

}