#include <iostream>

int inArray(int* array, int num);

int outArray(int* array, int num);

bool isOrderedArray(int* array, int num);

void permutationArray(int* array, int num);

int main()
{
	setlocale(LC_ALL, "RU");
	int num;
	std::cout << "Введите количество элементов в массиве: "; std::cin >> num;

	if (std::cin.fail() || num < 0) { std::cerr << "Invalid input!"; return 1; }
	if (num == 0) { std::cout << "Задан пустой массив"; return 2; }

	int* array = new int[num];

	if (inArray(array, num) == 1) { std::cerr << "Invalid input!"; return 1; }
	outArray(array, num);
	isOrderedArray(array, num) ? std::cout << "\ntrue\n" : std::cout << "\nfalse\n";
	permutationArray(array, num);
	outArray(array, num);

	return 0;
}

int inArray(int* array, int num)
{
	int var = 0;
	for (std::size_t i = 0; i < num; ++i) {
		std::cin >> var;

		if (std::cin.fail()) { return 1; }

		array[i] = var;
	}
	return 0;
}

int outArray(int* array, int num)
{
	for (std::size_t i = 0; i < num; ++i) {
		std::cout << array[i];

		if (i < (num - 1)) { std::cout << ","; }
	}
	return 0;
}

bool isOrderedArray(int* array, int num)
{
	for (std::size_t i = 1; i < num; ++i) {
		if (array[i - 1] > array[i]) { return false; }
	}
	return true;
}

void permutationArray(int* array, int num) {
	int var = 0;
	for (std::size_t i = 1; i < (num - num % 2); i += 2) {
		var = array[i - 1];
		array[i - 1] = array[i];
		array[i] = var;
	}
}

