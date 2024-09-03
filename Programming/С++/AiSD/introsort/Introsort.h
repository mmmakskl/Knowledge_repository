#pragma once
#include <iostream>
#include <algorithm>
#include<time.h>
#define FLAG_TO_INSERTIONSORT 16

void introsort(int* arr, const size_t length);
void introsortRecursive(int* arr, int start, int end, int deep);
void insertionSort(int* arr, const size_t length);
void heapSort(int* arr, int start, int end);
void heapify(int* arr, int start, int end, int i);
int partition(int* arr, int left, int right, int pivot);
void countTimeOfIntrosort(size_t length);
bool isSorted(int* arr,const size_t length);