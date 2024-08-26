#ifndef TIMSORT_HPP
#define TIMSORT_HPP
const int RUN = 32;

#include <iostream>

void merge(int* result, std::size_t begin, std::size_t mid, std::size_t end);

void insertion_sort(int* array, std::size_t begin, std::size_t end);

void tim_sort(int* array, std::size_t size);

void test();

void time(int* array, std::size_t size);

void fillArrayWithRandom(int* array, size_t size);

#endif