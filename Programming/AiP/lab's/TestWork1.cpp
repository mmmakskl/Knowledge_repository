#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int number0 = 0, number1 = 0, number2 = 0, count = 0;

	cin >> number0;

	if (cin.fail()) { cout << "Вы ввели не число!"; return 0; }

	if (number0 == 0) {
		return 0;
	}

	cin >> number1;

	if (cin.fail()) { cout << "Вы ввели не число!"; return 0; }

	if (number1 == 0) {
		return 0;
	}

	cin >> number2;

	if (cin.fail()) { cout << "Вы ввели не число!"; return 0; }

	if (number2 == 0 && number2 < number1 && number1 < number0) {
		cout << 1;
		return 0;
	}

	else if (number2 == 0) {
		cout << 0;
		return 0;
	}

	while (number2 != 0) {
		if (number1 < number0 && number1 > number2) {
			count++;
		}
		number0 = number1;
		number1 = number2;
		cin >> number2;
		if (cin.fail()) { cout << "Вы ввели не число!" << endl << "Результат работы программы: " << count; return 0; }

	}

	if (number0 > number1 && number1 > number2) {
		count++;
	}

	cout << "Результат работы программы: " << count;
	return 0;
}