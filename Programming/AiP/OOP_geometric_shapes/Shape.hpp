#pragma once
#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <cmath>
#include "FrameRectangle.hpp"

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual FrameRectangle getFrameRectagle() const = 0;
    virtual void scale(double kScale) = 0;
    virtual void move(double kX, double kY) = 0;
    virtual void move(Point newPos) = 0;
    virtual Shape* clone() const = 0;
    virtual const char* getName() const = 0;
    virtual ~Shape() {};
};

#endif
