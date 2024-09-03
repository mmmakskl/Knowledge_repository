#include "DictionaryList.h"
#include "tests.h"

int main()
{
    std::setlocale(LC_ALL, "ru");
    std::cout << "_______________testWithChar_______________\n";
    testWithChar();
    std::cout << "\n\n_______________testWithNumbers_______________\n";
    testWithNumbers();
    std::cout << "\n\n_______________testWithString_______________\n";
    testWithString();
    return 0;
}