#include <fstream> // ofstream, ifstream
#include <algorithm> // max
#include <functional> // function

#include "function.hpp"

using namespace kladkovoj;

Knapsack::Knapsack(int numItems, int maxWeight)
: maxWeight_(maxWeight), numItems_(numItems)
{}

void Knapsack::addItem(int weight, int value)
{
  weights_.push_back(weight);
  values_.push_back(value);
}

void Knapsack::writeToFile(const std::string& filename) const
{
  std::ofstream file(filename);
  if (!file.is_open())
  {
    throw std::invalid_argument("Error opening file for writing.");
  }

  file << maxWeight_ << ' ' << numItems_ << '\n';
  for (size_t i = 0; i < weights_.size(); ++i)
  {
    file << weights_[i] << ' ' << values_[i] << '\n';
  }

  file.close();
}

int Knapsack::knapsackDP() const
{
  std::vector<std::vector<int>> dp(numItems_ + 1, std::vector<int>(maxWeight_ + 1, 0));
  for (int i = 1; i <= numItems_; ++i)
  {
    for (int w = 1; w <= maxWeight_; ++w)
    {
      if (weights_[i - 1] <= w)
      {
        dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights_[i - 1]] + values_[i - 1]);
      }
      else
      {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  return dp[numItems_][maxWeight_];
}

int Knapsack::knapsackBacktracking() const
{
  int maxValue = 0;
  std::function<void(int, int, int)> backtrack = [&](int i, int currentWeight, int currentValue)
  {
    if (i == numItems_)
    {
      if (currentWeight <= maxWeight_)
      {
        maxValue = std::max(maxValue, currentValue);
      }
      return;
    }
    backtrack(i + 1, currentWeight, currentValue);
    backtrack(i + 1, currentWeight + weights_[i], currentValue + values_[i]);
  };
  backtrack(0, 0, 0);
  return maxValue;
}

int Knapsack::knapsackBranchAndBound() const
{
  struct Node
  {
    int level,
    profit,
    bound,
    weight;
  };

  auto bound = [&](const Node& u)
  {
    if (u.weight >= maxWeight_)
    {
      return 0;
    }
    int profitBound = u.profit;
    int j = u.level + 1;
    int totWeight = u.weight;
    while ((j < numItems_) && (totWeight + weights_[j] <= maxWeight_))
    {
      totWeight += weights_[j];
      profitBound += values_[j];
      j++;
    }
    if (j < numItems_)
    {
      profitBound += (maxWeight_ - totWeight) * values_[j] / weights_[j];
    }
    return profitBound;
  };

  std::vector<Node> Q;
  Node u, v;
  u.level = -1;
  u.profit = u.weight = 0;
  Q.push_back(u);
  int maxProfit = 0;

  while (!Q.empty())
  {
    u = Q.back();
    Q.pop_back();

    if (u.level == -1)
    {
      v.level = 0;
    }
    if (u.level == numItems_ - 1)
    {
      continue;
    }

    v.level = u.level + 1;
    v.weight = u.weight + weights_[v.level];
    v.profit = u.profit + values_[v.level];

    if (v.weight <= maxWeight_ && v.profit > maxProfit)
    {
      maxProfit = v.profit;
    }

    v.bound = bound(v);
    if (v.bound > maxProfit)
    {
      Q.push_back(v);
    }

    v.weight = u.weight;
    v.profit = u.profit;
    v.bound = bound(v);
    if (v.bound > maxProfit)
    {
      Q.push_back(v);
    }
  }
  return maxProfit;
}

int Knapsack::knapsackBruteForce() const
{
  int maxValue = 0;
  int numSubsets = 1 << numItems_;
  for (int subset = 0; subset < numSubsets; ++subset)
  {
    int totalWeight = 0, totalValue = 0;
    for (int i = 0; i < numItems_; ++i)
    {
      if (subset & (1 << i))
      {
        totalWeight += weights_[i];
        totalValue += values_[i];
      }
    }
    if (totalWeight <= maxWeight_)
    {
      maxValue = std::max(maxValue, totalValue);
    }
  }
  return maxValue;
}
