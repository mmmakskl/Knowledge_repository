#pragma once
#include<iostream>
#include<regex>
#include<string>
using namespace std;

#define ROWS 2
# define COLS 3
const string ERROR = "Непредвиденный символ";

int checkInput(const string& value);	// провекрка корректности вводимой переменной

void inArray(int (&arr)[ROWS][COLS],int rows,int cols);		// заполнение массива (обращение к элементам ведется через индексы) 

void inArrayPointer(int(&arr)[ROWS][COLS], int rows, int cols);		// заполнение массива (обращение к элементам ведется через указатели) 

void outArray(int (&arr)[ROWS][COLS]);		// вывод полученного массива на экран
