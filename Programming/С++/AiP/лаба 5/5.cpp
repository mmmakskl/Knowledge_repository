#include <iostream>
#include <string>
#include<exception>
#include"checkInput.h"    // функция, выполняющая проверку ввода данных
#include"inArray.h"      // функция, заполняющая массив введенными через cin значениями
#include"printArray.h"  //функция, выводящая заполненный массив на экран
using namespace std;

const int static_size = 7;  //размер встроенного массива
int main()
{
	setlocale(LC_ALL, "ru");
	string value = "";    //переменная, хранящая введенные данные до проверки их корректности
	int* arr = nullptr;  //выделение памяти для динамического массива
	int static_arr[static_size]{ 0 }; //встроенный массив
get_size:
	cout << "Введите число элементов массива\n";
	cin >> value;
	try
	{
		int size = checkInput(value);
		if (size <= 0) throw runtime_error("Размер массива должен принимать положительное значение");
		else
		{
			int* arr = new int[size] { 0 }; //динамический массив
			inArray(arr, size); 
			cout << "\nВвод элементов статического массива\n";
			inArray(static_arr, static_size);
			printArray(arr, size);
			printArray(static_arr, static_size);
		}
	} 
	catch (runtime_error& ex)
	{
		cerr << ex.what() << endl;
		goto get_size;
	}
	catch (bad_alloc& ex) 
	{
		cerr << ex.what() << endl;
		delete[] arr;
		exit(EXIT_FAILURE);
	}
	delete[] arr;
	return 0;
}
