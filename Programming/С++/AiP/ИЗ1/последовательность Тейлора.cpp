#include <iostream>
#include<string>
#include<exception>
#include <iomanip>
#include "functions.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string str = "";          // хранение переменных до проверки их корректности
    double start = 0.0,      // начало введенного пользователем диапазона
           end = 0.0,       // конец введенного пользователем диапазона
           step = 0.0;     // шаг интерввала
    int precision = 0;    //  точность вычислений
    try 
    {
        cout << "Введите начало диапазона\n x1 =\t ";
        cin >> str;
        start = checkDouble(str);
        cout << "Введите конец диапазона\n x2 =\t ";
        cin >> str;
        end = checkDouble(str);
        if (abs(start) >= 1 || abs(end) >= 1 || start> end) throw runtime_error("Границы диапазона указаны неверно");
        cout << "Введите шаг диапазона\n step =\t ";
        cin >> str;
        step = checkDouble(str);
        if (step <= 0.0)  throw runtime_error("Неверный шаг диапазона");
        cout << "Введите точность вычислений\n precision =\t ";
        cin >> str;
        precision = checkUnsigntInt(str);
        if (precision > 12 || precision == 0) throw runtime_error("Некорректная точность вычислений");
    }
    catch (runtime_error &ex)
    {
        cerr << ex.what() << "\n";
        exit(EXIT_FAILURE);
    }
    double absError = pow(0.1, precision);  // абсолютная погрешность
    cout << "  _____________________________________________\n";
    cout <<"||" << setw(4) << "x" << setw(4) << "|" << setw(14) << "expTaylor" << setw(5) << "|";
    cout << setw(10) << "exp" << setw(10) << "||" << endl;
    cout << "||_______|__________________|__________________||\n";
    for (start; start < end; start += step)
    {
        if (abs(start) < 1e-6) start = 0.0;
        cout << "||" << setw(5) << start << setw(3) << "|" << setprecision(precision +1) << setw(16) << expTaylor(start, absError) << setw(3) << "|"
        << setw(16) << exp(start)<<setw(4)<<"||" << endl;
    }
    cout << "||" << setw(5) << end << setw(3) << "|" << setprecision(precision + 1) << setw(16) << expTaylor(end, absError) << setw(3) << "|"
    << setw(16) << exp(end) << setw(4) << "||" << endl;
    cout << "||_______|__________________|__________________||\n";
    return 0;
}