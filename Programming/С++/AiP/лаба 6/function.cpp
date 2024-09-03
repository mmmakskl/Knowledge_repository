#include "function.h"

int checkInput(const string& value)
{
	regex regular("-?\\d+");
	if (regex_match(value, regular)) return stoi(value);
	else throw runtime_error(ERROR);
}

void inArray(int (&arr)[ROWS][COLS],int rows,int cols)
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


void inArrayPointer(int(&arr)[ROWS][COLS], int rows, int cols)
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
					*(*(arr+i)+j) = checkInput(value);
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

void outArray(int(&arr)[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			cout << "arr[" << i << "][" << j << "] =" << *(*(arr + i) + j) << "\n";
}

