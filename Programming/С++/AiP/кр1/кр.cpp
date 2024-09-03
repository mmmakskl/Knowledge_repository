#include<iostream>
using namespace std;
bool IsInt(double a)
{
	return (int)a == a;
}

int main()
{
	setlocale(LC_ALL, "ru");
	double a = 0;
	double b = 0;
	double c = 0;
	cout << "Введите 1 элемент последовательности\n" << " (для прекращения ввода введите '0')\n";
	cin >>c;
	if (cin.fail() || !IsInt(c))
	{
		cerr << "Ошибка ввода данных!\n";
		exit(EXIT_FAILURE);
	}	
	int count = 0;
	while (c != 0)
	{
		a = b;
		b = c;
		cout << "Вчедите следующий элемент последовательности\n" << " (для прекращения ввода введите '0')\n";
		cin >> c;
		
		if (cin.fail()|| !IsInt(c))
		{
			cerr << "Ошибка ввода данных!\n";
			exit(EXIT_FAILURE);

		}
		else
		{
			if (c == 0)
				break;
			else
			{

				if ((a != 0) && (b != 0))
				{
					if ((a > b) && (b > c))
						count++;
				}
			}
		}
	}
	if ((a == 0) || (b == 0)) cout << "Последовательность не содержит достаточного количества элементов\n";
	else
		cout << "Количество элементов, удовлетворяющих условию = "<<count << "\n";
	return 0;
}