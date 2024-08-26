#pragma once
#include<iostream>
#include<regex>
#include<string>
using namespace std;
#define ERROR "Непредвиденный символ"

int checkInput(const string& value);

void inArray( int** arr, int rows, int cols);

void inArrayPointer(int** arr, int rows, int cols);

void outArray( int **arr, int rows, int cols);

int ** allocateMemory(int** arr, int rows, int cols);

int ** deleteMemory(int** arr, int rows, int cols);

int getNumberOfOrdderedRows(int** arr, int rows, int cols);