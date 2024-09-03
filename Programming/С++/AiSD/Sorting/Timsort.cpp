#include "Timsort.hpp"

void merge(int* result, std::size_t begin, std::size_t mid, std::size_t end)
{
  std::size_t lenLeft = mid - begin + 1;
  std::size_t lenRight = end - mid;
  int* left = new int[lenLeft];
  int* right= new int[lenRight];

  for (std::size_t i = 0; i < (lenLeft); i++)
    left[i] = result[begin+i];
  for (std::size_t j = 0; j < (lenRight); j++)
    right[j] = result[mid + j + 1];

  std::size_t leftIn = 0, rightIn = 0, resIn = begin;
  while (leftIn != lenLeft && rightIn != lenRight)
  {
    if(left[leftIn] <= right[rightIn])
      result[resIn++] = left[leftIn++];
    else
      result[resIn++] = right[rightIn++];
  }

  while (leftIn < lenLeft)
    result[resIn++] = left[leftIn++];

  while (rightIn < lenRight)
    result[resIn++] = right[rightIn++];

  delete [] left;
  delete [] right;
}

void insertion_sort(int* array, std::size_t begin, std::size_t end)
{
  for(std::size_t i = begin + 1; i <= end; i++)
  {
    std::size_t j = i - 1;
    int key = array[i];
    while((array[j] > key) && (j >= begin))
    {
      array[j+1]= array[j];
      if(j == 0)
        break;
      j--;
    }
    if(j==0)
      array[j] = key;
    else
      array[j+1] = key;
  }
}

void tim_sort(int* array, std::size_t size)
{
  for (std::size_t i = 0; i < size; i += RUN)
  {
    std::size_t right = std::min((i + RUN - 1), (size - 1));
    bool isSorted = true;
    for (std::size_t j = i; j< right; j++)
    {
        if (array[j] > array[j+1])
        {
          isSorted = false;
          break;
        }
    }

    if (!isSorted)
      insertion_sort(array, i, right);
  }

  for (std::size_t j = RUN; j < size; j = 2 * j)
  {
    for (std::size_t begin = 0; begin < size; begin += (2 * j))
    {
      std::size_t mid = begin + j - 1;
      std::size_t end = std::min((begin + 2 * j - 1), (size - 1));

      if (mid < end)
      {
        merge(array, begin, mid, end);
      }
    }
  }
}