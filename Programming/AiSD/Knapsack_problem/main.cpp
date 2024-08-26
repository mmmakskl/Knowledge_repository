#include "KnapsackProblem.h"
#include <iostream>
#include <chrono>

const int NUM_ITEMS_1 = 10;
const int MAX_WEIGHT_1 = 50;
const int NUM_ITEMS_2 = 25;
const int MAX_WEIGHT_2 = 50;

int main()
{
  std::cout << "----- Knapsack Problem -----" << std::endl << std::endl;
  std::cout << "--- Solving the problem for 10 items ---" << std::endl << std::endl;

  Knapsack knapsack1(NUM_ITEMS_1, MAX_WEIGHT_1);

  knapsack1.printItems();

  auto begin1 = std::chrono::steady_clock::now();
  knapsack1.knapsackDP();
  auto end1 = std::chrono::steady_clock::now();
  auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
  std::cout << "The time: " << time1.count() << " microseconds" << std::endl << std::endl;

  auto begin2 = std::chrono::steady_clock::now();
  knapsack1.knapsackBacktracking();
  auto end2 = std::chrono::steady_clock::now();
  auto time2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
  std::cout << "The time: " << time2.count() << " microseconds" << std::endl << std::endl;

  auto begin3 = std::chrono::steady_clock::now();
  knapsack1.knapsackBranchAndBound();
  auto end3 = std::chrono::steady_clock::now();
  auto time3 = std::chrono::duration_cast<std::chrono::microseconds>(end3 - begin3);
  std::cout << "The time: " << time3.count() << " microseconds" << std::endl << std::endl;

  auto begin4 = std::chrono::steady_clock::now();
  knapsack1.knapsackBruteForce();
  auto end4 = std::chrono::steady_clock::now();
  auto time4 = std::chrono::duration_cast<std::chrono::microseconds>(end4 - begin4);
  std::cout << "The time: " << time4.count() << " microseconds" << std::endl << std::endl;

  std::cout << "--- Solving the problem for 25 items ---" << std::endl << std::endl;

  Knapsack knapsack2(NUM_ITEMS_2, MAX_WEIGHT_2);

  knapsack2.printItems();

  auto begin5 = std::chrono::steady_clock::now();
  knapsack2.knapsackDP();
  auto end5 = std::chrono::steady_clock::now();
  auto time5 = std::chrono::duration_cast<std::chrono::microseconds>(end5 - begin5);
  std::cout << "The time: " << time5.count() << " microseconds" << std::endl << std::endl;

  auto begin6 = std::chrono::steady_clock::now();
  knapsack2.knapsackBacktracking();
  auto end6 = std::chrono::steady_clock::now();
  auto time6 = std::chrono::duration_cast<std::chrono::microseconds>(end6 - begin6);
  std::cout << "The time: " << time6.count() << " microseconds" << std::endl << std::endl;

  auto begin7 = std::chrono::steady_clock::now();
  knapsack2.knapsackBranchAndBound();
  auto end7 = std::chrono::steady_clock::now();
  auto time7 = std::chrono::duration_cast<std::chrono::microseconds>(end7 - begin7);
  std::cout << "The time: " << time7.count() << " microseconds" << std::endl << std::endl;

  auto begin8 = std::chrono::steady_clock::now();
  knapsack2.knapsackBruteForce();
  auto end8 = std::chrono::steady_clock::now();
  auto time8 = std::chrono::duration_cast<std::chrono::microseconds>(end8 - begin8);
  std::cout << "The time: " << time8.count() << " microseconds" << std::endl << std::endl;

  return 0;
}