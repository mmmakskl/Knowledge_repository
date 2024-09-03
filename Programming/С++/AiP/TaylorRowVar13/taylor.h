#ifndef TAYLOR
#define TAYLOR
#include <iostream>
#include <cmath>
#include <iomanip>

double taylorFunc(double x, int numberMax, double absError);

void printTable(double minX, double maxX, double step, double absError, int numberMax);

#endif
