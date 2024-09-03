#include "functions.h"

int checkInput(const string& value)
{
	regex regular("-?\\d+");
	if (regex_match(value, regular)) return stoi(value);
	else throw runtime_error(ERROR);
}


void inArray(int** arr, int rows, int cols)
{
	bool test = true;
	string value = "";
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			do
			{
				cout << "¬ведите элемент массива\t";
				cin >> value;
				try
				{
					arr[i][j] = checkInput(value);
					test = true;
				}
				catch (runtime_error& ex)
				{
					cerr << ex.what() << "\n";
					test = false;
				}
			} while (!test);
		}
}

void inArrayForStatic(int(&arr)[ROWS][COLS], int rows, int cols)
{
	bool test = true;
	string value = "";
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			do
			{
				cout << "¬ведите элемент массива\t";
				cin >> value;
				try
				{
					arr[i][j] = checkInput(value);
					test = true;
				}
				catch (runtime_error& ex)
				{
					cerr << ex.what() << "\n";
					test = false;
				}
			} while (!test);
		}
}


void outArray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		cout << "\n" << i << "  строка\t";
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << "\t";

	}
}

void outArrayForStatic(int(&arr)[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i < ROWS; i++)
	{
		cout <<"\n" << i << "  строка\t";
		for (int j = 0; j < COLS; j++)
			cout<< arr[i][j] << "\t";

	}
}
int** allocateMemory(int** arr, int rows, int cols)
{
	arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols] {0};
	return arr;
}

int** deleteMemory(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		delete arr[i];
	delete[] arr;
	return arr;
}

int countOfSameElements(int** arr, int rows, int cols)
{
	int count = 0;
	bool  test = false;
	for (int i = 0; i < rows; i++)
	{
		test = false;
		for (int j = 0; j < cols-1; j++)
			for (int k = j + 1; k < cols; k++)
			{
				if (arr[i][j] == arr[i][k])
					test = true;
				if (test) break;
			}
		if (test) count++;
	}
	return count;
}

int countOfSameElementsForStatic(int(&arr)[ROWS][COLS], int rows, int cols)
{
	int count = 0;
	bool  test = false;
	for (int i = 0; i < rows; i++)
	{
		test = false;
		for (int j = 0; j < cols - 1; j++)
			for (int k = j + 1; k < cols; k++)
			{
				if (arr[i][j] == arr[i][k])
					test = true;
				if (test) break;
			}
		if (test) count++;
	}
	return count;
}