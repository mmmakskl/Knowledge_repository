#include "FrameRectangle.hpp"

FrameRectangle::FrameRectangle(): pos_(Point()), width_(0), height_(0) {};
FrameRectangle::FrameRectangle(Point pos, double width, double height): pos_(pos), width_(width), height_(height) {};
FrameRectangle::~FrameRectangle() {};

Point FrameRectangle::getPos() const
{
    return pos_;
}

double FrameRectangle::getWidth() const
{
    return width_;
}

double FrameRectangle::getHeight() const
{
    return height_;
}
