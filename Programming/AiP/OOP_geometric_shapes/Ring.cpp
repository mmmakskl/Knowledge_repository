#include "Ring.hpp"

Ring::Ring(): center_(Point()), radius_(0), radius2_(0) {}

Ring::Ring(Point center, double radius, double radius2): center_(center), radius_(radius), radius2_(radius2)
{
    if ((radius < 0.0) || (radius2 < 0.0))
        throw "Invalid radius parameters";
}

Ring::~Ring() {}

Ring* Ring::clone() const
{
    return new Ring(center_, radius_, radius2_);
}

double Ring::getArea() const
{
    return M_PI * pow(radius_, 2.0) - M_PI * pow(radius2_, 2.0);
}

FrameRectangle Ring::getFrameRectagle() const
{
    double radius = std::max(radius_, radius2_);
    double leftBottomX = center_.getX() - radius;
    double leftBottomY = center_.getY() - radius;
    double rightTopX = center_.getX() + radius;
    double rightTopY = center_.getY() + radius;
    return FrameRectangle(Point(center_.getX(), center_.getY()), radius*2.0, radius*2.0);
}

void Ring::move(double kX, double kY)
{
    center_ = Point(center_.getX() + kX, center_.getY() + kY);
}

void Ring::move(Point newPos)
{
    center_ = newPos;
}

const char *Ring::getName() const
{
    return "Ring";
}

void Ring::scale(double kScale)
{
    if (kScale < 0 or (typeid(kScale) != typeid(double)))
        throw "Invalid factor";
    radius_ *= kScale;
    radius2_ *= kScale;

}
