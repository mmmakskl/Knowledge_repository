#include "Point.hpp"

Point::Point(): x_(0.0), y_(0.0) {}

Point::Point(double x, double y): x_(x), y_(y) {}

Point::~Point(){}

double Point::getX() const
{
    return x_;
}

double Point::getY() const
{
    return y_;
}
