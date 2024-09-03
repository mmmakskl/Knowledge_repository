#include "Point.h"

Point::Point() { x_ = 0.0; y_ = 0.0; }
Point::Point(double x, double y) { x_ = x; y_ = y; }
Point::Point(const Point& a) {	x_ = a.x_;	y_ = a.y_;}

Point::~Point() {  }

void Point::setX(double x) { x_ = x; }
void Point::setY(double y) { y_ = y; }

double Point::getX() const { return x_; }
double Point::getY() const { return y_; }

double Point::getDistance(const Point a) const
{
	return sqrt(pow(x_ - a.x_, 2) + pow(y_ - a.y_, 2));
}

void iSpointInCircle(const Point a, const double r)
{
	sqrt(pow(a.getX(), 2) + pow(a.getY(), 2)) <= r ? std::cout << "����� �������� � ���� ������� " << r << "\n" :
		std::cout << "����� �� �������� � ���� ������� " << r << "\n";
}

// ���������� ���������� ���������
bool Point::operator == (const Point& point) const {	return (x_==point.x_) && (y_==point.y_);}

bool Point::operator < (const Point& point) const { return (pow(x_,2)+pow(y_,2)) < (pow(point.x_, 2) + pow(point.y_, 2)); }

bool Point::operator >= (const Point& point) const {	return (pow(x_, 2) + pow(y_, 2)) >= (pow(point.x_, 2) + pow(point.y_, 2)); }


//���������� ���������� ������������
Point& Point::operator = (const Point& point)
{
	x_ = point.x_;
	y_ = point.y_;
	return *this;
} 

Point Point::operator  + (const double k)const
{
	Point point(x_ + k, y_ + k);
	return point;
}

Point& Point::operator += (const double k)
{
	x_ += k;
	y_ += k;
	return *this;
}

//���������� ���������� ����� � ������
double checkInput(std::string& value)
{
	std::regex regular("-?\\d+,?\\d*");
	std::regex replace("\\.");
	value = std::regex_replace(value, replace, ",");
	if (std::regex_match(value, regular)) return std::stod(value);
	else throw std::invalid_argument(ERROR_OF_INPUT);
}

std::istream& operator >> (std::istream& stream, Point& point)
{
	std::string value1 = "";
	std::string value2 = "";
	std::cout << "���������� �����:\t";
	stream >> value1 >> value2;
	point.x_ = checkInput(value1);
	point.y_ = checkInput(value2);
	return stream;
}

std::ostream& operator << (std::ostream& stream, const Point& point)
{
	stream << "(" << point.x_ << ", " << point.y_ << ")";
	return stream;
}

// �������, ����������� ����� Point
void testPoint()
{
	std::cout << "������������ ������ Point\n";
	Point point1;
	Point point2;
	std::cin >> point1;
	std::cin >> point2;
	point1 == point2 ? std::cout << "����� ���������\n" : std::cout << "����� �� ���������\n";
	if (point1 < point2) std::cout << point1 << " < " << point2 << "\n";
	if (point1 >= point2) std::cout << point1 << " >= " << point2 << "\n";
	std::cout << "������� ����������, �� ������� ����� ���������� �����: ";
	std::string value = "";
	std::cin >> value;
	point1 = point1 + checkInput(value);
	point2 += checkInput(value);
	std::cout << "���������� �����:" << point1 << "\t" << point2 << "\n";
	std::cout << "����� ������������ ������ Point\n\n\n";
}

