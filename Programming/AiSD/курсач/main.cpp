#include<exception>
#include<fstream>
#include<sstream>
#include"Structs.h"
const std::string IRCORRECT_INPUT = "Ircorrect input\n";
const std::string ERROR_OF_OPENING = "File not open\n";

void testWithExample();

int main()
{
  try 
  {
    std::cout << "_____________________trial testing____________________\n";
    testWithExample();
    std::cout << "\n\n________________the main work of the program______________\n";
    std::ifstream file("test.txt");
    if (!file.is_open()) throw std::runtime_error(ERROR_OF_OPENING);
    AVL_Tree tree;
    std::string line;
    std::string word;
    while (std::getline(file,line))
    {
      std::istringstream iss (line);
      while(iss >> word)
        tree.insert(word);
    }
    tree.findMax();
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void testWithExample()
{
  AVL_Tree tree;
  std::cout << "Do you want to see a negative search option?\n(y/n):\t";
  std::string choice;
  std::cin >> choice;
  if (choice.length() > 1) throw std::runtime_error(IRCORRECT_INPUT);
  switch (choice[0])
  {
  case 'y': case 'Y':
    tree.search("word");
    break;
  case 'n': case 'N':
    tree.insert("word");
    tree.output();
    tree.search("word");
    tree.search("banana");
    tree.remove("word");
    break;
  default:
    throw std::runtime_error(IRCORRECT_INPUT);
  }

  std::cout << "\nVocabulary before insert elements:\n\t";
  tree.output();

  std::cout << "Do you want to see a negative remove option?\n(y/n):\t";
  std::cin >> choice;
  if (choice.length() > 1) throw std::runtime_error(IRCORRECT_INPUT);
  switch (choice[0])
  {
  case 'y': case 'Y':
    tree.remove("word");
    break;
  case 'n': case 'N':
    tree.insert("word");
    tree.insert("watch");
    tree.output();
    tree.remove("watch");
    tree.output();
    tree.remove("banana");
    break;
  default:
    throw std::runtime_error(IRCORRECT_INPUT);
  }

  tree.insert("apple");
  tree.insert("banana");
  tree.insert("apple");
  std::cout << "\nVocabulary after insert elements:\n\t";
  tree.output();

  std::cout << "Do you want to see a negative search option for the 3 maximum elements?\n(y/n):\t";
  std::cin >> choice;
  if (choice.length() > 1) throw std::runtime_error(IRCORRECT_INPUT);
  switch (choice[0])
  {
  case 'y': case 'Y':
    tree.remove("banana");
    std::cout << "Vocabulary after deleting the element:\n\t";
    tree.output();
    tree.findMax();
    break;
  case 'n': case 'N':
    tree.findMax();
    break;
  default:
    throw std::runtime_error(IRCORRECT_INPUT);
  }
}
