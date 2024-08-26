#include <iostream>
#include <fstream>  // ifstream, ofstream
#include <vector>  // vector
#include <random>  // rand
#include <memory>  // unique_ptr
#include <sstream>  // istringstream

#include "command.hpp"
#include "function.hpp"

using namespace kladkovoj;

std::unique_ptr<Knapsack> knapsack_;

void command::create(int capacity, int numItems, const std::string& filename)
{
  std::ofstream file(filename);
  if (!file)
  {
    throw std::runtime_error("Could not create file.");
  }

  file << capacity << ' ' << numItems << '\n';
  for (int i = 0; i < numItems; ++i)
  {
    int weight = rand() % 100 + 1;
    int value = rand() % 100 + 1;
    file << weight << ' ' << value << '\n';
  }
}

void command::create(const std::string& filename)
{
  std::ofstream file(filename);
  if (!file)
  {
    throw std::runtime_error("Could not create file.");
  }

  int capacity, numItems;
  std::cout << "Enter knapsack capacity and number of items: ";
  std::cin >> capacity >> numItems;

  if (std::cin.fail())
  {
    throw std::runtime_error("Invalid input.");
  }

  file << capacity << ' ' << numItems << '\n';
  for (int i = 0; i < numItems; ++i)
  {
    int weight = rand() % 100 + 1;
    int value = rand() % 100 + 1;
    file << weight << ' ' << value << '\n';
  }
}

void command::show(const std::vector<std::string>& tokens)
{
  if (tokens.size() != 2)
  {
    throw std::invalid_argument("SHOW requires a filename.");
  }
  std::ifstream file(tokens[1]);
  if (!file)
  {
    throw std::runtime_error("Could not open file.");
  }

  std::string firstLine;
  if (std::getline(file, firstLine))
  {
    std::istringstream iss(firstLine);
    std::size_t capacity, numItems;
    if (iss >> capacity >> numItems)
    {
      std::cout << "capacity: " << capacity << " number of items: " << numItems << '\n';
    }
    else
    {
      throw std::runtime_error("Invalid format.");
    }
  }

  std::size_t num = 1;
  std::string line;
  while (std::getline(file, line))
  {
    std::cout << num << ": " << line << '\n';
    num++;
  }
}

void command::solveDP(const std::string& filename)
{
  std::ifstream file(filename);
  if (!file)
  {
    throw std::runtime_error("Could not open file.");
  }

  int capacity, numItems;
  file >> capacity >> numItems;

  Knapsack knapsack(numItems, capacity);
  for (int i = 0; i < numItems; ++i)
  {
    int weight, value;
    file >> weight >> value;
    knapsack.addItem(weight, value);
  }

  int result = knapsack.knapsackDP();
  std::cout << "Maximum value (DP): " << result << '\n';
}

void command::solveBT(const std::string& filename)
{
  std::ifstream file(filename);
  if (!file)
  {
    throw std::runtime_error("Could not open file.");
  }

  int capacity, numItems;
  file >> capacity >> numItems;

  Knapsack knapsack(numItems, capacity);
  for (int i = 0; i < numItems; ++i)
  {
    int weight, value;
    file >> weight >> value;
    knapsack.addItem(weight, value);
  }

  int result = knapsack.knapsackBacktracking();
  std::cout << "Maximum value (BT): " << result << '\n';
}

void command::solveBB(const std::string& filename)
{
  std::ifstream file(filename);
  if (!file)
  {
    throw std::runtime_error("Could not open file.");
  }

  int capacity, numItems;
  file >> capacity >> numItems;

  Knapsack knapsack(numItems, capacity);
  for (int i = 0; i < numItems; ++i)
  {
    int weight, value;
    file >> weight >> value;
    knapsack.addItem(weight, value);
  }

  int result = knapsack.knapsackBranchAndBound();
  std::cout << "Maximum value (BB): " << result << '\n';
}

void command::solveBF(const std::string& filename)
{
  std::ifstream file(filename);
  if (!file)
  {
    throw std::runtime_error("Could not open file.");
  }

  int capacity, numItems;
  file >> capacity >> numItems;

  Knapsack knapsack(numItems, capacity);
  for (int i = 0; i < numItems; ++i)
  {
    int weight, value;
    file >> weight >> value;
    knapsack.addItem(weight, value);
  }

  int result = knapsack.knapsackBruteForce();
  std::cout << "Maximum value (BF): " << result << '\n';
}


void command::help()
{
  std::cout << "Available commands:\n";
  std::cout << "HELP - Show this help message\n";
  std::cout << "CREATE <capacity> <numItems> <filename> - Create a knapsack with random items and save to file\n";
  std::cout << "CREATE <filename> - create a backpack from a file\n";
  std::cout << "SHOW <filename> - Show contents of the file\n";
  std::cout << "SOLVE_DP <filename> - Solve knapsack problem using dynamic programming\n";
  std::cout << "SOLVE_BT <filename> - Solve knapsack problem using backtracking\n";
  std::cout << "SOLVE_BB <filename> - Solve knapsack problem using branch and bound\n";
  std::cout << "SOLVE_BF <filename> - Solve knapsack problem using brute force\n";
}
