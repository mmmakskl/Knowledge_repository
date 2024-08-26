#include "functions.h"

double checkDouble(string &x)
{
    regex regular("-?\\d+,\\d+");
    regex replace("\\.");
    x = regex_replace(x, replace, ",");
    if (regex_match(x, regular))  return stod(x);
    else throw runtime_error("Некорректный ввод данных");
}


int checkUnsigntInt(const string &x)
{
	regex regular ("\\d+");
	if (regex_match(x,regular) ) return stoi(x); 
    else throw runtime_error("Некорректный ввод данных");
}


double expTaylor(const double x, const double absError)
{
	double xInPow = 1.0;
	double res = 1.0;
	int factorial = 1;
	for (int i = 1; ; i++)
	{
		xInPow *= x;
		factorial *= i;
		res += xInPow / factorial;
		if (abs(xInPow / factorial) <= absError) break;
	}
	return res;
}