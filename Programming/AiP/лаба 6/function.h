#pragma once
#include<iostream>
#include<regex>
#include<string>
using namespace std;

#define ROWS 2
# define COLS 3
const string ERROR = "�������������� ������";

int checkInput(const string& value);	// ��������� ������������ �������� ����������

void inArray(int (&arr)[ROWS][COLS],int rows,int cols);		// ���������� ������� (��������� � ��������� ������� ����� �������) 

void inArrayPointer(int(&arr)[ROWS][COLS], int rows, int cols);		// ���������� ������� (��������� � ��������� ������� ����� ���������) 

void outArray(int (&arr)[ROWS][COLS]);		// ����� ����������� ������� �� �����
