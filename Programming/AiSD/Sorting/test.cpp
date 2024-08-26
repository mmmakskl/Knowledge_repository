#include "Timsort.hpp"
#include <time.h>
#include <chrono>
#include <iomanip>

void time(int* array, std::size_t size)
{
  auto start = std::chrono::high_resolution_clock::now();
  tim_sort(array, size);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> seconds = end - start;
  std::cout << std::setw(10) << std::setprecision(5) << std::fixed <<  size << ": " << seconds.count() << "s" << std::endl;
}

void fillArrayWithRandom(int* array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    int x = rand() * 100000 + rand();
    array[i] = x;
  }
}

bool isOrder(int* array, std::size_t size)
{
  bool isOrder = true;
  for (std::size_t i = 0; i < size - 1; i++)
  {
	if (array[i] > array[i + 1])
	{
    isOrder = false;
	}
  }
  return isOrder;
}

void test()
{
  std::cout << "--- TimSort sorting ---" << std::endl << std::endl;
  for (size_t size : {1000, 10000, 100000})
  {
    int* array = new int[size];
    fillArrayWithRandom(array, size);
    time(array, size);
    std::cout << "Is the array sorted? " << (isOrder(array, size)? "Yes" : "No" ) << std::endl;
    delete [] array;
  }
  std::cout << std::endl << "The best case: " << std::endl;
  int* array = new int[500000];
  for(std::size_t i; i < 500000; i++)
  {
    array[i] = i;
  }
  time(array, 500000);
  std::cout << "Is the array sorted? " << (isOrder(array, 500000)? "Yes" : "No" ) << std::endl;
  std::cout << std::endl << "The average and worst case: " << std::endl;
  fillArrayWithRandom(array, 500000);
  time(array, 500000);
  std::cout << "Is the array sorted? " << (isOrder(array, 500000)? "Yes" : "No" ) << std::endl;

  delete [] array;
}