#include "Triangle.h"

Triangle::Triangle()
{
	a_.setX(0.0); a_.setY(0.0);
	b_.setX(0.0); b_.setY(0.0);
	c_.setX(0.0); c_.setY(0.0);
}

Triangle::Triangle(Point a, Point b, Point c)
{
	a_ = a;
	b_ = b;
	c_ = c;
}

Triangle::Triangle(const Triangle& a)
{
	a_ = a.getA();
	b_ = a.getB();
	c_ = a.getC();
}

Triangle::~Triangle() { };

void Triangle::setA(Point a) { a_ = a; }
void Triangle::setB(Point b) { b_ = b; }
void Triangle::setC(Point c) { c_ = c; }

Point Triangle::getA() const { return a_; }
Point Triangle::getB() const { return b_; }
Point Triangle::getC() const { return c_; }

bool Triangle::isTriangle() const 
{ 
	double AB = a_.getDistance(b_);
	double AC = a_.getDistance(c_);
	double BC = b_.getDistance(c_);
	return ((AB + BC > AC) && (AB + AC > BC) && (BC + AC > AB)) ? EXIT_FAILURE : EXIT_SUCCESS;
}


double Triangle::getPerimeter() const
{
	double AB = a_.getDistance(b_);
	double AC = a_.getDistance(c_);
	double BC = b_.getDistance(c_);
	if (isTriangle()) return AB+BC+AC;
	else throw std::runtime_error(ERROR_OF_FIGURE);
}

//пергрузка операторов сравнения
bool Triangle::operator==(const Triangle& triangle) const
{
	if (isTriangle() && triangle.isTriangle())
		return (a_ == triangle.a_) && (b_ == triangle.b_) && (c_ == triangle.c_);
	else throw std::runtime_error(ERROR_OF_FIGURE);
}

bool Triangle::operator<(const Triangle& triangle) const
{
	double AB = a_.getDistance(b_);
	double AC = a_.getDistance(c_);
	double BC = b_.getDistance(c_);
	double square1 = sqrt(0.5*getPerimeter()*(0.5 * getPerimeter()-AB)*(0.5 * getPerimeter()-BC)*(0.5 * getPerimeter()-AC));
	AB = triangle.a_.getDistance(triangle.b_);
	AC = triangle.a_.getDistance(triangle.c_);
	BC = triangle.b_.getDistance(triangle.c_);
	double square2 = sqrt(0.5 * triangle.getPerimeter() * (0.5 * triangle.getPerimeter() - AB) * (0.5 * triangle.getPerimeter() - BC) * (0.5 * triangle.getPerimeter() - AC));
	return square1 < square2;
}

//перегрузка операторов присваивания
Triangle Triangle::operator + (const double k) const
{
	Triangle new_triangle(a_+k,b_+k,c_+k);
	return new_triangle;
}

Triangle& Triangle::operator+=(const double k)
{
	a_ += k;
	b_ += k;
	c_ += k;
	return *this;
}

//перегрузка операторов ввода и вывода
std::ostream& operator<<(std::ostream& stream, const Triangle& triangle)
{
	stream << "Координаты треугольника:  " << triangle.a_ << "  " << triangle.b_ <<"  "<<triangle.c_<< "\n";
	return stream;
}

std::istream& operator>>(std::istream& stream, Triangle& triangle)
{
	std::cout << "1 вершина:\t";
	stream >> triangle.a_;
	std::cout << "2 вершина:\t";
	stream >> triangle.b_;
	std::cout << "3 вершина:\t";
	stream>> triangle.c_;
	return stream;
}

//тестирование класса Triangle
void tetsTriangle()
{
	std::cout << "Тестирование класса Triangle\n";
	Triangle triangle1;
	Triangle triangle2;
	std::cin >> triangle1;
	std::cin >> triangle2;
	std::cout << triangle1 << triangle2;
	triangle1 == triangle2 ? std::cout << "Треугольники совпадают\n" : std::cout << "Треугольники не совпадают\n";
	triangle1 < triangle2 ? std::cout << "Площадь треугольника 1 меньше площади треугольника 2\n" : std::cout << "Площадь теругольника 2 больше или равна площади треугольника 1\n";
	std::cout << "Введите расстояние, на которое будут перемещены треугольники: ";
	std::string value = "";
	std::cin >> value;
	triangle1 = triangle1 + checkInput(value);
	triangle2 += checkInput(value);
	std::cout << triangle1 << triangle2;
	std::cout << "Конец тестирования класса Triangle\n";
};