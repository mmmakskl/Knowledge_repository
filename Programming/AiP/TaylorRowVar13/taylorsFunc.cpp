#include "taylor.h"

void printTable(double minX, double maxX, double step, double absError, int numberMax)
{
	char j = '|';
	std::cout << "\n--------------------------------------------------" << std::endl << "|    x    " << "| Taylor: sqrt(1+x) |" << std::setw(14) << " Cmath: sqrt(1+x)" << std::setw(2) << "|" << std::endl;
	double x = minX;
	while(x <= maxX)
	{
		if(x > -0.00001 && x < 0.00001)
			std::cout << "--------------------------------------------------" << std::endl << j << std::setw(6) << 0 << std::setw(4) << j << std::setw(13) << taylorFunc(x, numberMax, absError) << std::setw(7) << j << std::setw(12) << sqrt(1 + x) << std::setw(7) << j << std::endl;
		else if (x > 0)
			std::cout << "--------------------------------------------------" << std::endl << j << std::setw(6) << x << std::setw(4) << j << std::setw(13) << taylorFunc(x, numberMax, absError) << std::setw(7) << j << std::setw(12) << sqrt(1+x) << std::setw(7) << j << std::endl;
		else
			std::cout << "--------------------------------------------------" << std::endl << j << std::setw(6) << x << std::setw(4) << j << std::setw(13) << taylorFunc(x, numberMax, absError) << std::setw(7) << j << std::setw(12) << sqrt(1+x) << std::setw(7) << j << std::endl;
		x += step;
	}
	std::cout << "--------------------------------------------------\n";
}

double taylorFunc(double x, int numberMax, double absError)
{
	double res = 1.0;
    double term = 1;
	double absItem = 1;
    for(int i = 1; i <= numberMax; i++)
    {
        term *= (-1.0) * (2 * i - 1) * 2 * i * x / (i * i * 4) ;
        res += term / (1.0 - 2 * i);
		absItem = term / (1.0 - 2 * i);
    }
	if (std::fabs(absItem) > absError)
		throw std::invalid_argument(" ОШИБКА!!! Число слагаемых превышает максимальное и точность вычислений не достигнута\n");
	else
		return res;
}
