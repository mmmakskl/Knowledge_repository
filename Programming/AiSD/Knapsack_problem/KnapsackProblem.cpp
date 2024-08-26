#include "KnapsackProblem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Knapsack::Knapsack(int numItems, int maxWeight)
{
  n = numItems;
  W = maxWeight;
  items = new Item[n];
  srand(time(0));
  for (int i = 0; i < n; ++i) {
    items[i].weight = rand() % 100 + 1;
    items[i].value = rand() % 100 + 1;
  }
}

Knapsack::~Knapsack()
{
  delete[] items;
}

void Knapsack::printItems()
{
  std::cout << "Items (weight, value):\n";
  for (int i = 0; i < n; ++i) {
    if (i % 10 == 0 && i > 1)
    {
      std::cout << std::endl;
    }
    std::cout << "(" << items[i].weight << ", " << items[i].value << ") ";
  }
  std::cout << std::endl << std::endl;
}

void Knapsack::knapsackDP()
{
  int** dp = new int* [n + 1];
  for (int i = 0; i <= n; ++i) {
    dp[i] = new int[W + 1];
  }

  for (int i = 0; i <= n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (i == 0 || w == 0) {
        dp[i][w] = 0;
      }
      else if (items[i - 1].weight <= w) {
        dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
      }
      else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  std::cout << "Dynamic Programming: Maximum value is " << dp[n][W] << "\n";
  printSelectedItems(dp);

  for (int i = 0; i <= n; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
}

void Knapsack::knapsackBacktracking()
{
  int maxValue = 0;
  bool* bestSet = new bool[n];
  bool* currentSet = new bool[n];

  knapsackBacktrackingUtil(0, 0, 0, maxValue, bestSet, currentSet);

  std::cout << "Backtracking: Maximum value is " << maxValue << "\n";
  printSelectedItems(bestSet);

  delete[] bestSet;
  delete[] currentSet;
}

void Knapsack::knapsackBacktrackingUtil(int i, int currentWeight, int currentValue, int& maxValue, bool* bestSet, bool* currentSet)
{
  if (i == n) {
    if (currentWeight <= W && currentValue > maxValue) {
      maxValue = currentValue;
      for (int j = 0; j < n; ++j) {
        bestSet[j] = currentSet[j];
      }
    }
    return;
  }
  currentSet[i] = true;
  knapsackBacktrackingUtil(i + 1, currentWeight + items[i].weight, currentValue + items[i].value, maxValue, bestSet, currentSet);

  currentSet[i] = false;
  knapsackBacktrackingUtil(i + 1, currentWeight, currentValue, maxValue, bestSet, currentSet);
}

void Knapsack::knapsackBranchAndBound()
{
  int maxValue = 0;
  bool* bestSet = new bool[n];
  bool* currentSet = new bool[n];

  knapsackBranchAndBoundUtil(0, 0, 0, maxValue, bestSet, currentSet);

  std::cout << "Branch and Bound: Maximum value is " << maxValue << "\n";
  printSelectedItems(bestSet);

  delete[] bestSet;
  delete[] currentSet;
}

void Knapsack::knapsackBranchAndBoundUtil(int i, int currentWeight, int currentValue, int& maxValue, bool* bestSet, bool* currentSet)
{
  if (i == n) {
    if (currentWeight <= W && currentValue > maxValue) {
      maxValue = currentValue;
      for (int j = 0; j < n; ++j) {
        bestSet[j] = currentSet[j];
      }
    }
    return;
  }

  int bound = currentValue;
  for (int j = i; j < n; ++j) {
    bound += items[j].value;
  }

  if (bound <= maxValue) {
    return;
  }

  if (currentWeight + items[i].weight <= W) {
    currentSet[i] = true;
    knapsackBranchAndBoundUtil(i + 1, currentWeight + items[i].weight, currentValue + items[i].value, maxValue, bestSet, currentSet);
  }

  currentSet[i] = false;
  knapsackBranchAndBoundUtil(i + 1, currentWeight, currentValue, maxValue, bestSet, currentSet);
}

void Knapsack::knapsackBruteForce()
{
  int maxValue = 0;
  bool* bestSet = new bool[n];

  int totalSubsets = 1 << n;
  for (int subset = 0; subset < totalSubsets; ++subset) {
    int weightSum = 0;
    int valueSum = 0;
    bool* currentSet = new bool[n];

    for (int i = 0; i < n; ++i) {
      if (subset & (1 << i)) {
        weightSum += items[i].weight;
        valueSum += items[i].value;
        currentSet[i] = true;
      }
      else {
        currentSet[i] = false;
      }
    }

    if (weightSum <= W && valueSum > maxValue) {
      maxValue = valueSum;
      for (int i = 0; i < n; ++i) {
        bestSet[i] = currentSet[i];
      }
    }

    delete[] currentSet;
  }

  std::cout << "Brute Force: Maximum value is " << maxValue << "\n";
  printSelectedItems(bestSet);

  delete[] bestSet;
}

void Knapsack::printSelectedItems(int** dp)
{
  int w = W;
  std::cout << "Selected items: \n";
  for (int i = n; i > 0 && w > 0; --i) {
    if (dp[i][w] != dp[i - 1][w]) {
      std::cout << "(" << items[i - 1].weight << ", " << items[i - 1].value << ")";
      w -= items[i - 1].weight;
    }
  }
  std::cout << std::endl;
}

void Knapsack::printSelectedItems(bool* selectedItems)
{
  std::cout << "Selected items: \n";
  for (int i = 0; i < n; ++i) {
    if (selectedItems[i]) {
      std::cout << "(" << items[i].weight << ", " << items[i].value << ")";
    }
  }
  std::cout << std::endl;
}
