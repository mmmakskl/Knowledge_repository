#include <iostream>
using namespace std;

bool IsInteger(double N)
{
	if (N == (int)N) return 1;
	else return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");
	double N = 0;
	cout << "Введите длину катетов равнобедренного прямоугольного треугольника\n" << "(число должно принимать целочисленное значене)\n";
	cin >> N;
	if (cin.fail() || (N<=0) || !IsInteger(N))
	{
		cerr << "Введены некорректные данные!\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= i; j++)
				cout << "* ";
			cout <<"\n";
		}
	}
	return 0;
}