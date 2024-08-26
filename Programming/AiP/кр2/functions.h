#pragma once
#include<iostream>
#include<regex>
#include<string>
using namespace std;

#define ROWS 2
# define COLS 3
const string ERROR = "Непредвиденный символ";

int checkInput(const string &value);

void inArray(int** arr, int rows, int cols);

void outArray(int** arr, int rows, int cols);

int** allocateMemory(int** arr, int rows, int cols);

int** deleteMemory(int** arr, int rows, int cols);

int countOfSameElements(int** arr, int rows, int cols);

void inArrayForStatic(int(&arr)[ROWS][COLS], int rows, int cols);

void outArrayForStatic(int(&arr)[ROWS][COLS], int rows, int cols);

int countOfSameElementsForStatic(int (&arr)[ROWS][COLS], int rows, int cols);