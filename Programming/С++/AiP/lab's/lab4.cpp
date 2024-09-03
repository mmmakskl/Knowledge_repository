////# 4.1.1 #
// 
//#include <iostream>
//
//int max3(int num1, int num2, int num3) {
//	int max = -10000000000;
//	if (num1 >= num2 && num1 >= num3) {
//		max = num1;
//	}
//	if (num3 >= num2 && num3 >= num1) {
//		max = num3;
//	}
//	if (num2 >= num1 && num2 >= num3) {
//		max = num2;
//	}
//	return max;
//}
//
//int main() {
//	setlocale(LC_ALL, "RU");
//	int num1, num2, num3, num4, num5;
//	std::cout << "Введите 5 целых чисел: ";
//	std::cin >> num1 >> num2 >> num3 >> num4 >> num5;
//	if (std::cin.fail()) {
//		std::cout << "Invalid input!";
//		return 1;
//	}
//	std::cout << "Максимальное значение = " << max3(max3(num1, num2, num3), num5, num4);
//	return 0;
//}

//# 4.1.2 #
//
//#include <iostream>
//#include <string>
//
//bool digitExists(int digit, int number) {
//	std::string numberStr = std::to_string(number); //Преобразование числа в строку
//	char digitChar = (char)('0' + digit); //Преобразование цифры в символ
//	
//	for (char c : numberStr) {
//		if (digitChar == c && c!='0') {
//			return true;
//		}
//	}
//	return false;
//}
//
//int main() {
//	setlocale(LC_ALL, "RU");
//	int digit, number;
//
//	std::cout << "Введите цифру от 0 до 9: "; std::cin >> digit;
//	if (std::cin.fail() || digit/10 > 0) { std::cout << "Invalid input!"; return 1; } //Проверка правильности ввода цифры
//	
//	std::cout << "Введите любое число: "; std::cin >> number;
//	if (std::cin.fail()) { std::cout << "Invalid input!"; return 1; } //Проверка правильности ввода числа
//
//	digitExists(digit, number) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
//  digitExists(digit, number) ? std::cout << "Цифра " << digit << " присутствует в числе " << number : std::cout << "Цифра " << digit << " не присутствует в числе " << number;
//	
//	return 0;
//}

////# 4.1.3 #
//
//#include <iostream>
//#include <string>
//
//bool palindrom(long int number) {
//	std::string numberStr = std::to_string(number);
//	std::string reverseNumber;
//
//	for (char c : numberStr){ reverseNumber = c + reverseNumber; }
//
//	return numberStr == reverseNumber;
//}
//
//int main() {
//	setlocale(LC_ALL, "RU");
//	long int number = 0;
//
//	std::cout << "Введите число: "; std::cin >> number;
//	if (std::cin.fail()) { std::cout << "Invalid input!"; return 1; }
//
//	palindrom(number) ? std::cout << "TRUE" << std::endl : std::cout << "FALSE" << std::endl;
//  palindrom(number) ? std::cout << "Данное число является палиндромом" : std::cout << "Число не является палиндромом";
// 
//  return 0
//}

////# 4.1.4 #
//
//#include <iostream>
//
//bool simpleNumber(int number) {
//	for (int i = 2; i <= sqrt(number); i++) {
//		if (number % i == 0) { return false; }
//	}
//	return true;
//}
//
//int main() {
//	setlocale(LC_ALL, "RU");
//	int number = 0;
//	
//	std::cout << "Введите число: "; std::cin >> number;
//	if (std::cin.fail()) { std::cout << "Invalid input!"; return 1; }
//
//	simpleNumber(number) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
//	simpleNumber(number) ? std::cout << "Число простое" : std::cout << "Число не простое";
//	return 0;
//}

////# 4.1.5 #
//
//#include <iostream>
//
//int binNumber(int number) {
//    int count = 0;
//
//    while (number) {
//        count += number % 2;
//        number /= 2;
//    }
//
//    return count;
//}
//
//int main() {
//	setlocale(LC_ALL, "RU");
//	int number = 0;
//	
//    std::cout << "Введите число: "; std::cin >> number;
//	if (std::cin.fail()) { std::cout << "Invalid input!"; return 1; }
//    
//    if (binNumber(number) == 1){ std::cout << "В двоичной записи числа " << number << " " << binNumber(number) << " еденицa"; }
//    
//    else if(binNumber(number) >= 2 && binNumber(number) <= 4) { std::cout << "В двоичной записи числа " << number << " " << binNumber(number) << " еденицы"; }
//    
//    else { std::cout << "В двоичной записи числа " << number << " " << binNumber(number) << " едениц"; }
//}

////# 4.2 #
// 1) могут быть в любом месте, главное не забыть запятую
// 
// 2) функция получает доступ к аргументу в вызывающей программе
// 
// 3) ошибка компиляции
// 
// 4) функция, не возвращающая значение имеет тип void когда аргументы передаются по ссылке, функция имеет доступ к переменным вызывающей
// 
// 5)р = fTest(а, к);
//   р = fTest(а + 2, к);
// 
// 6) 3: 101 101 1: 20 100 2: 101
// 
// 7) 1,0,1;
//    2,1,1;
