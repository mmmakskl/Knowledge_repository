#include "taylor.h"

int main()
{
	setlocale(LC_ALL, "russian");
	double maxX = 0, minX = 0, absError = 0, step = 0;
	int numberMax = 0;

	try
	{
		std::cout << "������� ������� ��� x" << std::endl << "|x| < 1" << std::endl << "���������� ��������� �������� x: ";
		std::cin >> minX;
		if (!std::cin)
			throw std::invalid_argument("�������� ���� �����\n");
		if (minX >= 1 || minX <= -1)
			throw std::invalid_argument("������� ���������� � ��������� (-1;1)\n");

		std::cout << "����������� ��������� �������� x: ";
		std::cin >> maxX;
		if (!std::cin)
			throw std::invalid_argument("�������� ���� �����\n");
		if (maxX >= 1 || maxX <= -1)
			throw std::invalid_argument("������� ���������� � ��������� (-1;1)\n");

		std::cout << "������� ��� ���������: "; std::cin >> step;
		if (std::cin.fail())
		if (!std::cin)
			throw std::invalid_argument("�������� ���� �����\n");
        if (step >= 1)
            throw std::invalid_argument("��� ������ ���� ������ 1\n");

		std::cout << "������� �������� ���������� �����������: ";
		std::cin >> absError;
		if (!std::cin)
			throw std::invalid_argument("�������� ���� �����\n");
		if (absError <= 0)
			throw std::invalid_argument("����������� ���������� ������ ���� ������ ������������� ������\n");

		std::cout << "������� ������������ ���������� ��������� � ������������������: ";
		std::cin >> numberMax;
		if (!std::cin)
			throw std::invalid_argument("�������� ���� �����\n");
		if (numberMax < 1)
			throw std::invalid_argument("����� ��������� ������ ���� ������������� � ����� ������\n");

		printTable(minX, maxX, step, absError, numberMax);
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
