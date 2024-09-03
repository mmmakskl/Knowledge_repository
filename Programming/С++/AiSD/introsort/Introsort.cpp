#include "Introsort.h"

void countTimeOfIntrosort(size_t length)
{
	int* arr = new int [length] {0};
	clock_t start, end;

	//лучший случай 
	for (int i = 0; i < length; ++i)
		arr[i] = i;
	start = clock();
	introsort(arr, length);
	end = clock();
	std::cout << "the best case: " << (double)(end - start) / CLOCKS_PER_SEC << " s\n";
	isSorted(arr, length) ? std::cout << "Array is sorted\n" : std::cout << "Array isn't sorted\n";

	//средний случай
	for (int i = 0; i < length; ++i)
		arr[i] = rand();
	start = clock();
	introsort(arr, length);
	end = clock();
	std::cout << "the average case: " << (double)(end - start) / CLOCKS_PER_SEC << " s\n";
	isSorted(arr, length) ? std::cout << "Array is sorted\n" : std::cout << "Array isn't sorted\n";

	//худший случай
	for (int i = length; i > 0; --i)
		arr[length - i] = i;
	start = clock();
	introsort(arr, length);
	end = clock();
	std::cout << "the worst case: " << (double)(end - start) / CLOCKS_PER_SEC << " s\n";
	isSorted(arr, length) ? std::cout << "Array is sorted\n" : std::cout << "Array isn't sorted\n";
	delete[] arr;
}

bool isSorted(int* arr, const size_t length)
{
	for (int i = 1; i < length; ++i)
		if (arr[i - 1] > arr[i])
			return false;
	return true;
}
void introsort(int* arr, const size_t length)
{
	int deep = std::floor(2 * log(length));
	introsortRecursive(arr, 0, length - 1, deep);
}

void introsortRecursive(int* arr, int start, int end, int deep)
{
	if (end - start <= FLAG_TO_INSERTIONSORT)
	{
		insertionSort(arr, end);
		return;
	}
	if (deep == 0)
	{
		heapSort(arr, start, end);
		return;
	}
	int pivot = arr[start] + arr[end] + arr[(end + start) / 2]
		- std::min({ arr[start], arr[end], arr[(end + start) / 2] })
		- std::max({ arr[start],arr[end], arr[(end + start) / 2] });
	int position;
	position = partition(arr, start, end, pivot);
	introsortRecursive(arr, start, position, deep - 1);
	introsortRecursive(arr, position, end, deep - 1);
}

void insertionSort(int* arr, const size_t length)
{
	for (int i = 1; i <= length; ++i)
	{
		int value = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > value)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = value;
	}
}

void heapSort(int* arr, int start, int end)
{
	for (int i = end / 2 - 1; i >= start; --i) {
		heapify(arr, start, end, i);
	}
	for (int i = end - 1; i > start; --i) {
		std::swap(arr[start], arr[i]);
		heapify(arr, start, i, 0);
	}
}

void heapify(int* arr, int start, int end, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < end && arr[left] > arr[largest]) largest = left;

	if (right < end && arr[right] > arr[largest]) largest = right;

	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		heapify(arr, start, end, largest);
	}
}

int partition(int* arr, int left, int right, int pivot)
{
	while (left <= right)
	{
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right)
		{
			std::swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	return left;
}
