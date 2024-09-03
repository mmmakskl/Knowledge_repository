#include"function.h"


int main()
{
	setlocale(LC_ALL, "ru");
	int arr[ROWS][COLS] = { 0 };
	string value = "" ;			// переменная, хранящая выбор пользователя до проверки корректности ввода
	int choiсе = 0;				// выбор пользователя 
	bool test = false;			
	cout << "Заполнение статичческого массива\n";
	while (!test)
	{
	cout << " 1- обращение к элементам массива через индексы\n 2 - обращение к элементам массива через указатели\n"
		<<"Выбор:\t";
	cin >> value;
	try
	{
		choiсе = checkInput(value);
		switch (choiсе)
		{
		case 1: {inArray(arr,ROWS,COLS); test = true; break; }
		case 2: {inArrayPointer(arr, ROWS, COLS); test = true; break; }
		default:
		{
			cout << "\nНекорректный выбор\n";
			test = false;
		}
		}
	}
	catch (runtime_error &ex)
	{
		cout << "\n" << ex.what() << "\n";
		test = false;
	}
	}
	cout << "\n\nПолученный статического массив:\n";
	outArray(arr);
	return 0;
}
