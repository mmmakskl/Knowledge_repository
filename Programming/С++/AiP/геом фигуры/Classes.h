#pragma once
#include<iostream>
#include <iomanip>
#include<regex>
using std::cin;
using std::cout;
const std::string ERROR_OF_INPUT = "Некорректный ввод\n";
const std::string ERROR_OF_FIGURE = "Фигура задана некорректно\n";


class Point
{
	friend class CompositeShape;
	friend class Concave;
	friend class Square;
	friend class FrameRectangle;
	friend std::ostream& operator << (std::ostream& stream, const Point& point);
	friend std::istream& operator >> (std::istream& stream,  Point& point);
public:
	Point();
	Point(double x, double y);
	Point(const Point& point);
	~Point();
	double getDistance(const Point& point)const;
	Point& operator = (const Point *point);
	Point& operator + (const double value)const;
	Point& operator + (const Point &point);
	Point& operator - (const double value)const;
	Point& operator - (const Point& point);
	Point& operator * (const double value);
private:
	double x_, y_;
};

class FrameRectangle
{
public:
	FrameRectangle(double width, double height, Point pos);
	~FrameRectangle();
	Point getLeftDown() const;
	Point getRightTop() const;
	Point getMiddle() const;
	double getHeight() const;
	double getWidth() const;
private:
	double width_, height_;
	Point pos_;
};

class Shape
{
public:
	virtual double getArea() const = 0;
	virtual FrameRectangle getFrameRectangle()const = 0;
	virtual void move(const double x, const double y) = 0;
	virtual void move(const Point &point) = 0;
	virtual Shape* clone() = 0;
	virtual std::string  getName()const = 0;
	virtual Point getMiddle()const = 0;
	virtual void scale(double k) = 0;
};

class Square : public Shape
{
public:
	Square();
	Square(const Square &sq);
	~Square();
	double getArea()const override;
	FrameRectangle getFrameRectangle()const override; 
	void move(const double x, const double y) override;
	void move(const Point& point) override;
	Shape* clone() override;
	std::string getName() const override;
	Point getMiddle() const override;
	Square& operator =  (const Square &square);
	void scale(double k) override;

private:
	Point A_, middle_;
	double length_;
};

class Concave : public Shape
{
public:
	Concave();
	Concave(const Concave& cn);
	~Concave();
	double getArea()const override;
	FrameRectangle getFrameRectangle()const override;
	void move(const Point& point) override;
	void move(const double x, const double y);
	Shape* clone() override;
	Concave& operator = (const Concave& triangle);
	std::string getName()const override;
	Point getMiddle() const override;
	void scale(double k) override;
private:
	Point A_, B_, C_, D_;
};

double inputToDouble(std::string& value);
bool isTriangle(const Point& A, const  Point& B, const Point& C);
float getSquare(const Point& A, const Point& B, const Point& C);
void getInfo(const Shape& figure);