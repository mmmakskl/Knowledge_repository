#include<fstream>
#include"C_str_Functions.h"
using namespace std;

const string IN_FILE = "in.txt";
const string OUT_FILE = "out.txt";
const string ERR_OF_OPENING = "Ошибка открытия файла";
const string ERR_OF_TYPE = "Длина строки задана некорректно";


int main()
{
	int result = EXIT_SUCCESS;
	setlocale(LC_ALL, "ru");
	ifstream in(IN_FILE);
	ofstream out(OUT_FILE);
	char *strFileIN = nullptr; // исходная строка
	char *strFileOut = nullptr; // полученная строка
	try 
	{
		if (!in.is_open() || !out.is_open())
			throw ios_base::failure(ERR_OF_OPENING);
		int length = 0;
		in >> length;
		if (in.fail()  || length <= 0)
			throw invalid_argument(ERR_OF_TYPE);
		strFileIN = new char[length + 1] ();
		in.ignore();
		in.read(strFileIN, length);
		cout << "Исходная строка\n (Если исходная строка была больше заданной длины, то она была обрезана)\n";
		showStr(strFileIN);
		cout << "Выберите функцию\n 1 - Удаление всех цифр\n 2 - Замена прописных букв строчными\nВыбор:\t";
		string value = "";
		cin >> value;
		int choice = checkInput(value);
		strFileOut = new char[length + 1] ();
		switch (choice)
		{
			case 1:
				deleteDigitsFromStr(strFileOut, strFileIN);
				out << strFileOut << "\n";
				cout << "Полученная строка:\t";
				showStr(strFileOut);
				break;
			case 2: 
				convertToLowercase(strFileOut, strFileIN); 
				out << strFileOut << "\n";
				cout << "Полученная строка:\t";
				showStr(strFileOut);
				break;
			default:
				cerr << ERROR << "\n"; 
				result =  EXIT_FAILURE; 
		}	
	}
	catch(ios_base::failure &ex)
	{
		cerr << ex.what() << "\n";
		result  = EXIT_FAILURE;
	}
	catch (invalid_argument &ex)
	{
		cerr << ex.what() << "\n";
		result =  EXIT_FAILURE;
	}
	catch (bad_alloc& ex)
	{
		cerr << ex.what() << "\n";
		result = EXIT_FAILURE;
	}
	in.close();
	out.close();
	delete[]strFileIN;
	delete[]strFileOut;
	return result;
}
