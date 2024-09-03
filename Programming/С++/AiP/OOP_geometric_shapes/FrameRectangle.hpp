#pragma once
#ifndef FRAMERECTANGLE_HPP
#define FRAMERECTANGLE_HPP
#include "Point.hpp"

class FrameRectangle
{
private:
    Point pos_;
    double width_;
    double height_;
public:
    FrameRectangle();
    FrameRectangle(Point pos, double width, double height);
    ~FrameRectangle();
    Point getPos() const;
    double getWidth() const;
    double getHeight() const;
};

#endif
