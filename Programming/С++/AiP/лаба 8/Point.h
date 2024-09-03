#pragma once
#include<iostream>
#include<cmath>
#include<regex>

const std::string ERROR_OF_INPUT = "Некорректный ввод данных\n";

class Point
{
	//перегрузка операторов ввода и вывода
	friend std::ostream& operator << (std::ostream& stream, const Point& point);
	friend std::istream& operator >> (std::istream& stream, Point& point);

public:
	Point();
	Point(double x, double y);
	Point(const Point& a);
	~Point();
	void setX(double x);
	void setY(double y);
	double getX()const;
	double getY() const;
	double getDistance(const Point a)const;

	//перегрузка операторов сравнения и присваивания
	bool operator == (const Point& point) const;
	bool operator < (const Point& point) const;
	bool operator >= (const Point& point) const;
	Point& operator = (const Point& point);
	Point operator + (const double k)const;
	Point& operator += (const double k);

private:
	double x_,
		y_;
};

double checkInput(std::string& value);
void iSpointInCircle(const Point a, const double r);
void testPoint();