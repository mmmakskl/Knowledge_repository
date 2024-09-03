#pragma once
#include"Point.h"
const std::string ERROR_OF_FIGURE = "������ �� �������� �������������\n";

class Triangle
{
	//���������� ���������� ����� � ������
	friend std::ostream& operator << (std::ostream& stream, const Triangle& triangle);
	friend std::istream& operator >> (std::istream& stream, Triangle& triangle);
public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Triangle(const Triangle& a);
	~Triangle();
	void setA(Point a);
	void setB(Point b);
	void setC(Point c);
	Point getA() const;
	Point getB() const;
	Point getC() const;
	bool isTriangle()const;
	double getPerimeter() const;

	//���������� ���������� ��������� � ������������
	bool operator == (const Triangle& triangle) const;
	bool operator < (const Triangle& triangle) const;
	Triangle operator + (const double k) const;
	Triangle& operator += (const double k);
private:
	Point a_, b_, c_;
};

void tetsTriangle();
