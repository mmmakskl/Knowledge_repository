#include <iostream>
#include "String.h"

int main()
{
	try {
		setlocale(LC_ALL, "ru");
		testingString();
	}
	catch (std::runtime_error& ex)
	{
		std::cerr << ex.what();
		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cout << "Что-то пошло не так :(\n";
		return EXIT_FAILURE;
	}
	return 0;
}


