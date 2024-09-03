#include "Rectangle.hpp"

Rectangle::Rectangle(): a_(Point()), b_(Point()) {}

Rectangle::Rectangle(Point a, Point b): a_(a), b_(b)
{
    if ((typeid(a.getX()) != typeid(double)) || (typeid(a.getY())) != typeid(double) || (typeid(b.getX()) != typeid(double)) || (typeid(b.getY()) != typeid(double)))
        throw "Not double argument";
}

Rectangle* Rectangle::clone() const
{
    return new Rectangle(a_, b_);
}

Rectangle::~Rectangle() {}

double Rectangle::getArea() const
{
    return abs((a_.getX() -b_.getX()) * (a_.getY() - b_.getY()));
}

FrameRectangle Rectangle::getFrameRectagle() const
{
    double centerX = (a_.getX() + b_.getX())/ 2.0;
    double centerY = (a_.getY() + b_.getY())/ 2.0;
    double width = abs(b_.getX() - a_.getX());
    double height = abs(b_.getY() - a_.getY());
    return FrameRectangle(Point(centerX, centerY), width, height);
}

void Rectangle::scale(double kScale)
{
    if (kScale < 0 or (typeid(kScale) != typeid(double)))
        throw "Invalid factor";
    double centerX = (a_.getX() + b_.getX())/ 2.0;
    double centerY = (a_.getY() + b_.getY())/ 2.0;

    double width = abs(b_.getX() - a_.getX());
    double height = abs(b_.getY() - a_.getY());

    double new_width = width * kScale;
    double new_height = height * kScale;

    a_ = Point(centerX - new_width / 2.0, centerY - new_height / 2.0);
    b_ = Point(centerX + new_width / 2.0, centerY + new_height / 2.0);
}

void Rectangle::move(double kX, double kY)
{
    a_ = Point(a_.getX() + kX, a_.getY() + kY);
    b_ = Point(b_.getX() + kX, b_.getY() + kY);
}

void Rectangle::move(Point newPos)
{
    double kX = newPos.getX() - a_.getX();
    double kY = newPos.getY() - a_.getY();
    move(kX, kY);
}

const char* Rectangle::getName() const
{
    return "Rectangle";
}
