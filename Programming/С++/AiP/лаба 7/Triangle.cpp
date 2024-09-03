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

Triangle::~Triangle() {};

void Triangle::setA(Point a){a_ = a;}

void Triangle::setB(Point b) {b_ = b;}

void Triangle::setC(Point c) {c_ = c;}

Point Triangle::getA() const {return a_;}

Point Triangle::getB() const { return b_;}

Point Triangle::getC() const { return c_; }

bool Triangle::isTriangle() const
{
	double AB = a_.getDistance(b_);
	double AC = a_.getDistance(c_);
	double BC = b_.getDistance(c_);
	return ((AB + BC > AC) && (AB + AC > BC) && (BC + AC > AB)) ? EXIT_FAILURE : EXIT_SUCCESS;
	
}

void Triangle::move(double k)
{
	a_.move(k);
	b_.move(k);
	c_.move(k);
}

double Triangle::getPerimeter() const
{
	 if (isTriangle()) return a_.getDistance(b_) + a_.getDistance(c_) + b_.getDistance(c_);
	 else throw std::runtime_error(ERROR_OF_FIGURE);

}

bool Triangle::isEqual(const Triangle a) const
{
	return (a_.isEqual(a.getA()) && b_.isEqual(a.getB()) && c_.isEqual(a.getC())) ? EXIT_FAILURE : EXIT_FAILURE;
}

void isEqualSquare(const Triangle a,const Triangle b)
{
	if (a.isTriangle() && b.isTriangle())
	{
		double AB = a.getA().getDistance(a.getB());
		double AC = a.getA().getDistance(a.getC());
		double BC = a.getB().getDistance(a.getC());
		double square_1 = sqrt(0.5 * a.getPerimeter() * (0.5 * a.getPerimeter() - AB) * (0.5 * a.getPerimeter() - AC) * (0.5 * a.getPerimeter() - BC));
		AB = b.getA().getDistance(b.getB());
		AC = b.getA().getDistance(b.getC());
		BC = b.getB().getDistance(b.getC());
		double square_2 = sqrt(0.5 * b.getPerimeter() * (0.5 * b.getPerimeter() - AB) * (0.5 * b.getPerimeter() - AC) * (0.5 * b.getPerimeter() - BC));
		square_1 == square_2 ?  std::cout << "Площади равны\n" :  std::cout << "Площади не равны\n";
	}
		else throw std::runtime_error(ERROR_OF_FIGURE);
}

void output(const Triangle a)
{
	output(a.getA());
	output(a.getB());
	output(a.getC());
}