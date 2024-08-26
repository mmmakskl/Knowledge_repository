#pragma once
#include<iostream>
#include<cmath>
#include<regex>

const std::string ERROR_OF_INPUT = "Некорректный ввод данных";

class Point
{
public:
	Point();
	Point(double x, double y);
	Point(const Point& a);
	~Point();
	void setX(double x);
	void setY(double y);
	double getX()const;
	double getY() const;
	bool isEqual(const Point a)const;
	double getDistance(const Point a)const;
	void move(double k);

private:
	double x_,
		y_;
};

double checkInput(std::string &value);
void iSpointInCircle(const Point a, const double r);
void input(Point &a);
void output(const Point a);