#pragma once
#include"Point.h"
const std::string ERROR_OF_FIGURE = "Фигура не является треугольником";

class Triangle
{
public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Triangle(const Triangle &a);
	~Triangle();
	void setA(Point a);
	void setB(Point b);
	void setC(Point c);
	Point getA() const;
	Point getB() const;
	Point getC() const;
	bool isTriangle()const;
	void move(double k);
	double getPerimeter() const;
	bool isEqual(const Triangle a)const;
private:
	Point a_, b_, c_;
};

void isEqualSquare(const Triangle a, const  Triangle b);
void output(const Triangle a);