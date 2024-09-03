#include"Point.h";
#include"Triangle.h"

int main()
{
	setlocale(LC_ALL, "ru");
	try {
		testPoint();
		tetsTriangle();
		
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what();
		exit(EXIT_FAILURE);
	}
	catch (std::runtime_error& ex)
	{
		std::cerr << ex.what();
		exit(EXIT_FAILURE);
	}
	return 0;
}