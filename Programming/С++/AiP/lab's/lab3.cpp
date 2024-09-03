//# 3.1.1 #

//#include <iostream>

//using namespace std;

//int main() {
//	int sideLenght;
//	cin >> sideLenght;
//	for (int i = 1; i <= sideLenght; i++) {
//		for (int j = 0; j < i; j++) {
//			cout << "*";
//		}
//		cout << endl;
//	}
//}

//# 3.1.2 #

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int sideLenght, rhombusSyze, rhombusCenter, fillIndex, nFill;
//	
//	cin >> sideLenght;
//	
//	rhombusSyze = (sideLenght * 2) - 1;
//	rhombusCenter = rhombusSyze / 2;
//	fillIndex = rhombusCenter;
//	nFill = 1;
//
//    for (int i = 0; i < rhombusSyze; i++) {
//        for (int j = 0; j <= fillIndex; j++) {
//            if (j == fillIndex) {
//                for (int fill = 0; fill < nFill; fill++) {
//                    cout << "* ";
//                }
//            }
//            cout << "  ";
//        }
//        cout << endl;
//
//        if (i < rhombusCenter) {
//            fillIndex--;
//            nFill += 2;
//        }
//        else {
//            fillIndex++;
//            nFill -= 2;
//        }
//    }
//    return 0;
//}

//# 3.1.3 #

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int number = 0, degree = 0, numberxdegree = 1;
//
//	cin >> number;
//
//	while (numberxdegree <= number) {
//		cout << "2 ^ " << degree++ << " = " << numberxdegree << endl;
//		numberxdegree *= 2;
//	}
//	return 0;
//}

//# 3.1.4 #

//#include <iostream>
//
//using namespace std;
//
//int main() {
//    int number = 0;
//
//    cin >> number;
//
//    while (number % 2 == 0) {
//        number /= 2;
//    }
//
//    if (number == 1) {
//        cout << "YES";
//    }
//    else {
//        cout << "NO";
//    }
//
//    return 0;
//}

//# 3.1.5 #

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	double run, needToRun;
//
//	cin >> run >> needToRun;
//
//	int days = 1;
//	double path = run;
//
//	for (days = 1; path < needToRun; days++, path += path * 1.1);
//
//	cout << "\n" << days;
//
//	return 0;
//}

//# 3.1.6 #

//#include <iostream>
//
//using namespace std;
//
//int fib(int num) {
//    if (num == 0 || num == 1) return num;
//    else return fib(num - 1) + fib(num - 2);
//}
//
//int main() {
//    int number;
//    cin >> number;
//    cout << fib(number);
//    return 0;
//}

//# 3.2 #

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	setlocale(LC_ALL, "RU");
//	int count_max = 0, count_min = 0, count_p = 0, count_g = 0;
//	double max = 0, min = 20000000000000, sum_p = 0, sum_g = 0, input;
//	cin >> input;
//	if (cin.fail()) {
//		cout << "Вы ввели не число" << endl;
//		return 0;
//	}
//	while (input != 0) {
//		count_g++;
//		sum_g += input;
//
//		if (input > 0) {
//			count_p++;
//			sum_p += input;
//		}
//
//		if (input > max) {
//			max = input;
//			count_max = count_g;
//		}
//
//		if (input < min) {
//			min = input;
//			count_min = count_g;
//		}
//		cin >> input;
//		if (cin.fail()) {
//			cout << "Вы ввели не число" << endl;
//			return 0;
//		}
//		}
//		double AvGen = sum_g / count_g;
//		double AvPos = sum_p / count_p;
//
//		cout << "Суммa всех введенных чисел - " << sum_g << endl << "Среднее арифметическое всех введенных чисел - " << AvGen << endl << "Среднее арифметическое введенных положительных чисел - " << AvPos << endl << "Максимальное положительное значение - " << max << " Его номер - " << count_max << endl << "Минимальное положительное значение - " << min << " Его номер - " << count_min << endl;
//}