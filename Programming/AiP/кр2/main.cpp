#include"functions.h"

int main()
{
	setlocale(LC_ALL, "ru");
	int** arr = nullptr;
	bool test = false;
	int rows = 0;
	int cols = 0;
	string value = "";
	int arr_static[ROWS][COLS] = {0};
	while (!test)
	{
		try
		{
			test = true;
			cout << "Введите количество строк динамического масства:\t";
			cin >> value;
			rows = checkInput(value);
			if (rows <= 0) throw runtime_error("Количество строк динамического массива должно принимать положительное значение");
			cout << "Введите количество столбцов динамического масства:\t";
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
		cout << "\nЗаполнение динамического массива\n ";
		inArray(arr, rows, cols);
		cout << "\nЗаполнение статического  массива\n ";
		inArrayForStatic(arr_static,ROWS, COLS);
		cout << "\nПолученный динамический массив:\n";
		outArray(arr, rows, cols);
		cout << "\n\nПолученный статический массив массив:\n";
		outArrayForStatic(arr_static, ROWS, COLS);
		cout << "\n\nКоличество  сторок с повторяющимися элементами в динамическом массиве =\t"<<countOfSameElements(arr, rows, cols)<<"\n";
		cout << "\nКоличество  сторок с повторяющимися элементами в статическом массиве =\t" << countOfSameElementsForStatic(arr_static,	ROWS, COLS) << "\n";
	}
	catch (bad_alloc& ex)
	{
		cerr << "\n" << ex.what() << "\n";
		deleteMemory(arr, rows, cols);
		exit(EXIT_FAILURE);
	}
	arr = deleteMemory(arr, rows, cols);
	return 0;
}
