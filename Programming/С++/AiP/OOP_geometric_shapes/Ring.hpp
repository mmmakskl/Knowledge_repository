#pragma once
#ifndef RING_HPP
#define RING_HPP
#include "Point.hpp"
#include "Shape.hpp"

class Ring: public Shape
{
private:
    Point center_;
    double radius_;
    double radius2_;
public:
    Ring();
    Ring(Point center, double radius, double radius2);
    Ring* clone() const override;
    ~Ring();
    double getArea() const override;
    FrameRectangle getFrameRectagle() const override;
    void move(double kX, double kY) override;
    void move(Point newPos) override;
    const char* getName() const override;
    void scale(double kScale) override;
};


#endif
