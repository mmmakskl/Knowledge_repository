#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int a, b, c;
	cout << "Введите 3 целых числа для сравнения:\n (ввод чисел осуществляется через пробел) \n";
	cin >> a >> b >> c;
	if (cin.fail())
	{
		cerr << "Ошибка ввода!";
		exit(EXIT_FAILURE);
	}

	else
		if (max(max(a, b), c) == a) cout <<"Максимальное из чисел:\t"<<" a =  " << a << "\n";
		else 
			if (max(max(a, b), c) == b) cout << "Максимальное из чисел:\t" << "b =  " <<b << "\n";
			else cout << "Максимальное из чисел:\t" << " c =  " << c << "\n";

	return 0;
}