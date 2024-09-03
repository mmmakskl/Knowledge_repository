#pragma once
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Point.hpp"
#include "Shape.hpp"

class Rectangle: public Shape
{
private:
    Point a_;
    Point b_;
public:
    Rectangle();
    Rectangle(Point a, Point b);
    Rectangle* clone() const override;
    ~Rectangle();
    double getArea() const override;
    FrameRectangle getFrameRectagle() const override;
    void scale(double kScale) override;
    void move(double kX, double kY) override;
    void move(Point newPos) override;
    const char* getName() const override;
};

#endif
