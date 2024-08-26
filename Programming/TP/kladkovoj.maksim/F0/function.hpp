#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>
#include <vector>

namespace kladkovoj
{
  class Knapsack
  {
  public:
    Knapsack(int numItems, int maxWeight);
    void addItem(int weight, int value);
    void writeToFile(const std::string& filename) const;
    int knapsackDP() const;
    int knapsackBacktracking() const;
    int knapsackBranchAndBound() const;
    int knapsackBruteForce() const;

  private:
    int maxWeight_;
    int numItems_;
    std::vector<int> weights_;
    std::vector<int> values_;
  };
}

#endif
