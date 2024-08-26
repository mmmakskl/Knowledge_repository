#pragma once
#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include "Shape.hpp"
#include <exception>
#include <limits>

class CompositeShape: public Shape
{
private:
    std::size_t size_ = 0;
    std::size_t numShapes_ = 0;
    Shape** shapes_{ nullptr };
    Point calculateCenter(const FrameRectangle& rect) const
    {
        double centerX = (rect.getPos().getX());
        double centerY = (rect.getPos().getY());
        return Point(centerX, centerY);
    }
public:
    CompositeShape();
    CompositeShape(std::size_t size);
    CompositeShape* clone() const override;
    ~CompositeShape();
    void move(double kX, double kY) override;
    void move(Point newPos) override;
    void scale(double kScale) override;
    void push_back(Shape* shape);
    FrameRectangle getFrameRectagle() const override;
    const char* getName() const override;
    double getArea() const override;
};
#endif
