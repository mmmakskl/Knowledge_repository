#include <iostream>
#include<string>
using namespace std;

// функция, проверяющая корректность ввода данных
bool checkInput(double N)
{
	 if (cin.fail() || (int(N) != N))
	{
		cerr << "Ошибка ввода данных!\n";
		return EXIT_FAILURE;
	}
	else return EXIT_SUCCESS;
}

//Вспомогательная функция, представлющая число в двоичном виде
string toBinary(int N)
{
	string strbin = "";
	while (N > 0)
	{
		strbin += to_string(N%2);
		N /= 2;
	}
	reverse(strbin.begin(), strbin.end());
	return strbin;
}

//Функция, определяющая является ли число палиндромом
int isPalindrome( int N)
{
	string str1 = toBinary(N);
	string str2 = toBinary(N);
	reverse(str2.begin(), str2.end());
	return (str1 == str2) ? EXIT_FAILURE: EXIT_SUCCESS;
}

//функция, опhеделяющая ялвляется ли чило простым
bool isPrime(int N)
{
	bool isDivisor = 0;
	if (N < 0) N *= -1;
	for (int i = 2; i<=ceil(sqrt(N));i++)
		if (N % i == 0)
		{
			isDivisor = 1;
			break;
		}
	return (isDivisor|| N==0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main()
{
	setlocale(LC_ALL, "ru");
	double change = 0; //переменная, хранящая выбор функции пользователем
	double N = 0; // Переменная, хранящая обрабатываемое пользователем числож
	cout << "Выбор функции:\n 1 - является ли чило палиндромом \n 2 - является ли число простым\n 0 - выход\n";
	cout << "Введите число : \t";
	cin >> change;
	if (checkInput(change)) exit(EXIT_FAILURE);
	else
	{
		switch ((int)change)
		{
			case 1 :
			{
				cout << "Введите число для проверки : \t";
				cin >> N;
				if (checkInput(N)) exit(EXIT_FAILURE);
				else
				{
					if (N < 0) cerr << "Число не может принимать отрицательных значений!\n";
					else
					{
					cout << "Число палиндром?\t";
					isPalindrome((int)N) ? cout << "Да\n" : cout << "Нет\n";
					}
				}
				break;
			}
			case 2:
			{
				cout << "Введите число для проверки : \t";
				cin >> N;
				if (checkInput(N)) exit(EXIT_FAILURE);
				else
				{
					cout << "Число простое?\t\t";
					isPrime((int)N) ? cout << "Да\n" : cout << "Нет\n";
				}
				break;
			}
			case 0:
				exit(EXIT_SUCCESS);
			default: 
			{
				cerr << "Введено неверное число\n";
				exit(EXIT_FAILURE);
			
			}
		}
	}
	return 0;
}