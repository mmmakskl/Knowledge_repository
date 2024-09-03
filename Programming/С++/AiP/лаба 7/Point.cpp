#include "Point.h"

Point::Point() { x_ = 0.0; y_ = 0.0; }
Point::Point(double x, double y) { x_ = x; y_ = y; }

Point::Point(const Point& a)
{
	x_ = a.x_;
	y_ = a.y_;
}

Point::~Point() { }

void Point::setX(double x) { x_ = x; }

void Point::setY(double y) { y_ = y; }

double Point::getX() const { return x_; }

double Point::getY() const { return y_; }

bool Point::isEqual(const Point a)const
{
	return  (x_ == a.x_ && y_ == a.y_) ? EXIT_FAILURE : EXIT_SUCCESS;
}

double Point::getDistance(const Point a) const
{
	return sqrt(pow(x_ - a.x_, 2) + pow(y_ - a.y_, 2));
}

void Point::move(double k)
{
	x_ += k;
	y_ += k;
}

void iSpointInCircle(const Point a,const double r)
{
	sqrt(pow(a.getX(), 2) + pow(a.getY(), 2)) <= r ? std::cout << "Точка попадает в круг радиуса " << r << "\n" :
	std::cout << "Точка не попадает в круг радиуса " << r << "\n";
}

double checkInput(std::string &value)
{
	std::regex regular("-?\\d+,?\\d*");
	std::regex replace("\\.");
	value = std::regex_replace(value, replace, ",");
	if (std::regex_match(value, regular)) return std::stod(value);
	else throw std::invalid_argument(ERROR_OF_INPUT);
}
void input(Point &a)
{
	std::string value = "";
	std::cout << "Введите координаты точки\n";
	std::cout << " x =\t";
	std::cin >>value;
	a.setX(checkInput(value));
	std::cout << " y =\t";
	std::cin >> value;
	checkInput(value);
	a.setY(checkInput(value));
}

void output(const Point a)
{
	std::cout << "(" << a.getX() << ", " << a.getY() << ")\n";
}