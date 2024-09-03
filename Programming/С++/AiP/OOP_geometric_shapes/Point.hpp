#pragma once
#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

class Point
{
private:
    double x_;
    double y_;
public:
    Point();
    Point(double x, double y);
    ~Point();
    double getX() const;
    double getY() const;
};

#endif
