#include<exception>
#include"functions.h"

int main()
{
	setlocale(LC_ALL, "ru");
	int** arr = nullptr;
	bool test = false;
	int rows = 0;
	int cols = 0;
	string value = "";
	int arr_static[2][3] = { 0 };
	while(!test)
	{
		try
		{
			test = true;
			cout << "Введите количество строк динамического масства:\t";
			cin >> value;
			rows = checkInput(value);
			if (rows <= 0) throw runtime_error("Количество строк динамического массива должно принимать положительное значение");
			cout << "Введите столбцов динамического масства:\t";
			cin >> value;
			cols = checkInput(value);
			if (cols <= 0) throw runtime_error("Количество столбцов динамического массива должно принимать положительное значение");
		}
		catch (runtime_error& ex)
		{
			cerr << "\n" << ex.what() << "\n";
			test = false;
		}
	}
	try
	{
		arr = allocateMemory(arr, rows, cols);
		cout << "\nЗаполнение динамического массива\n";
		//inArray(arr, rows, cols);
		inArrayPointer(arr, rows, cols);
		cout << "\nПолученный динамический массив:\n";
		outArray(arr, rows, cols);
	}
	catch (bad_alloc& ex)
	{
		cerr << "\n" << ex.what() << "\n";
		deleteMemory(arr, rows, cols);
		exit(EXIT_FAILURE);
	}


	cout << getNumberOfOrdderedRows(arr, rows, cols) << endl;
	arr = deleteMemory(arr, rows, cols);
	return 0;
}
