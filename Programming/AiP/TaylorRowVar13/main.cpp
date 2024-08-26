#include "taylor.h"

int main()
{
	setlocale(LC_ALL, "russian");
	double maxX = 0, minX = 0, absError = 0, step = 0;
	int numberMax = 0;

	try
	{
		std::cout << "Введите границы для x" << std::endl << "|x| < 1" << std::endl << "Минимально возможное значение x: ";
		std::cin >> minX;
		if (!std::cin)
			throw std::invalid_argument("Неверный ввод числа\n");
		if (minX >= 1 || minX <= -1)
			throw std::invalid_argument("Функция определена в интервале (-1;1)\n");

		std::cout << "Максимально возможное значение x: ";
		std::cin >> maxX;
		if (!std::cin)
			throw std::invalid_argument("Неверный ввод числа\n");
		if (maxX >= 1 || maxX <= -1)
			throw std::invalid_argument("Функция определена в интервале (-1;1)\n");

		std::cout << "Введите шаг интервала: "; std::cin >> step;
		if (std::cin.fail())
		if (!std::cin)
			throw std::invalid_argument("Неверный ввод числа\n");
        if (step >= 1)
            throw std::invalid_argument("Шаг должен быть меньше 1\n");

		std::cout << "Введите значение абсолютной погрешности: ";
		std::cin >> absError;
		if (!std::cin)
			throw std::invalid_argument("Неверный ввод числа\n");
		if (absError <= 0)
			throw std::invalid_argument("Погрешность вычислений должна быть задана положительным числом\n");

		std::cout << "Введите максимальное количество слогаемых в последовательности: ";
		std::cin >> numberMax;
		if (!std::cin)
			throw std::invalid_argument("Неверный ввод числа\n");
		if (numberMax < 1)
			throw std::invalid_argument("Число слагаемых должно быть положительным и целым числом\n");

		printTable(minX, maxX, step, absError, numberMax);
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
