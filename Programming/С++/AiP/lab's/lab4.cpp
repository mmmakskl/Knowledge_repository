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
//	std::cout << "������� 5 ����� �����: ";
//	std::cin >> num1 >> num2 >> num3 >> num4 >> num5;
//	if (std::cin.fail()) {
//		std::cout << "Invalid input!";
//		return 1;
//	}
//	std::cout << "������������ �������� = " << max3(max3(num1, num2, num3), num5, num4);
//	return 0;
//}

//# 4.1.2 #
//
//#include <iostream>
//#include <string>
//
//bool digitExists(int digit, int number) {
//	std::string numberStr = std::to_string(number); //�������������� ����� � ������
//	char digitChar = (char)('0' + digit); //�������������� ����� � ������
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
//	std::cout << "������� ����� �� 0 �� 9: "; std::cin >> digit;
//	if (std::cin.fail() || digit/10 > 0) { std::cout << "Invalid input!"; return 1; } //�������� ������������ ����� �����
//	
//	std::cout << "������� ����� �����: "; std::cin >> number;
//	if (std::cin.fail()) { std::cout << "Invalid input!"; return 1; } //�������� ������������ ����� �����
//
//	digitExists(digit, number) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
//  digitExists(digit, number) ? std::cout << "����� " << digit << " ������������ � ����� " << number : std::cout << "����� " << digit << " �� ������������ � ����� " << number;
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
//	std::cout << "������� �����: "; std::cin >> number;
//	if (std::cin.fail()) { std::cout << "Invalid input!"; return 1; }
//
//	palindrom(number) ? std::cout << "TRUE" << std::endl : std::cout << "FALSE" << std::endl;
//  palindrom(number) ? std::cout << "������ ����� �������� �����������" : std::cout << "����� �� �������� �����������";
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
//	std::cout << "������� �����: "; std::cin >> number;
//	if (std::cin.fail()) { std::cout << "Invalid input!"; return 1; }
//
//	simpleNumber(number) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
//	simpleNumber(number) ? std::cout << "����� �������" : std::cout << "����� �� �������";
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
//    std::cout << "������� �����: "; std::cin >> number;
//	if (std::cin.fail()) { std::cout << "Invalid input!"; return 1; }
//    
//    if (binNumber(number) == 1){ std::cout << "� �������� ������ ����� " << number << " " << binNumber(number) << " ������a"; }
//    
//    else if(binNumber(number) >= 2 && binNumber(number) <= 4) { std::cout << "� �������� ������ ����� " << number << " " << binNumber(number) << " �������"; }
//    
//    else { std::cout << "� �������� ������ ����� " << number << " " << binNumber(number) << " ������"; }
//}

////# 4.2 #
// 1) ����� ���� � ����� �����, ������� �� ������ �������
// 
// 2) ������� �������� ������ � ��������� � ���������� ���������
// 
// 3) ������ ����������
// 
// 4) �������, �� ������������ �������� ����� ��� void ����� ��������� ���������� �� ������, ������� ����� ������ � ���������� ����������
// 
// 5)� = fTest(�, �);
//   � = fTest(� + 2, �);
// 
// 6) 3: 101 101 1: 20 100 2: 101
// 
// 7) 1,0,1;
//    2,1,1;
