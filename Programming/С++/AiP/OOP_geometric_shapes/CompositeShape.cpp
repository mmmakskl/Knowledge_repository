#include "CompositeShape.hpp"

CompositeShape::CompositeShape(): size_(0), shapes_(new Shape*[size_]) {}

CompositeShape::CompositeShape(std::size_t size): size_(size), shapes_(new Shape*[size_]) {};

CompositeShape* CompositeShape::clone() const
{
    CompositeShape* newComposite = new CompositeShape(size_);
    for (std::size_t i = 0; i < numShapes_; i++)
    {
        newComposite->push_back(shapes_[i]->clone());
    }
    return newComposite;
}

CompositeShape::~CompositeShape()
{
    for (std::size_t i = 0; i < numShapes_; i++)
    {
        delete shapes_[i];
    }
    delete[] shapes_;
}

void CompositeShape::move(double kX, double kY)
{
    FrameRectangle frame = getFrameRectagle();
    Point center = calculateCenter(frame);
    double newCenterX = center.getX() + kX;
    double newCenterY = center.getY() + kY;

    double moveX = newCenterX - center.getX();
    double moveY = newCenterY - center.getY();
    for (std::size_t i = 0; i < numShapes_; i++)
        shapes_[i]->move(moveX, moveY);
}

void CompositeShape::move(Point newPos)
{
    FrameRectangle frame = getFrameRectagle();
    Point center = calculateCenter(frame);

    double moveX = newPos.getX() - center.getX();
    double moveY = newPos.getY() - center.getY();

    for (std::size_t i = 0; i < numShapes_; i++)
        shapes_[i]->move(moveX, moveY);
}


void CompositeShape::scale(double kScale)
{
    FrameRectangle frame = getFrameRectagle();
    Point center = calculateCenter(frame);

    for (std::size_t i = 0; i < numShapes_; i++)
    {
        Point centerShape = shapes_[i]->getFrameRectagle().getPos();
        double kX = (centerShape.getX() - center.getX()) * (kScale - 1.0);
        double kY = (centerShape.getY() - center.getY()) * (kScale - 1.0);
        shapes_[i]->move(kX, kY);
        shapes_[i]->scale(kScale);
    }
}

void CompositeShape::push_back(Shape* shape)
{
    if(numShapes_ >= size_)
        throw "index greater than array size";
    shapes_[numShapes_] = shape;
    ++numShapes_;
}

FrameRectangle CompositeShape::getFrameRectagle() const
{
    if (numShapes_ == 0)
    {
        return FrameRectangle(Point(0.0,0.0), 0.0, 0.0);
        throw "No shapes for composite shape";
    }
    double minX = std::numeric_limits<double>::max(), minY = std::numeric_limits<double>::max(), maxX = std::numeric_limits<double>::lowest(), maxY = std::numeric_limits<double>::lowest();
    for (std::size_t i = 0; i < numShapes_; i++)
    {
        FrameRectangle frame = shapes_[i]->getFrameRectagle();
        const Point leftBottom(frame.getPos().getX() - frame.getWidth()/2.0, frame.getPos().getY() - frame.getHeight()/2.0);
        const Point rightTop(leftBottom.getX() + frame.getWidth(), leftBottom.getY() + frame.getHeight());
        minX = std::min(minX, leftBottom.getX());
        minY = std::min(minY, leftBottom.getY());
        maxX = std::max(maxX, rightTop.getX());
        maxY = std::max(maxY, rightTop.getY());
    }
    double width = abs(maxX - minX);
    double height = abs(maxY - minY);
    double centerX = (minX + maxX)/ 2.0;
    double centerY = (maxY + minY)/ 2.0;

    return FrameRectangle(Point(centerX, centerY), width, height);
}

const char* CompositeShape::getName() const
{
    return "Composite";
}

double CompositeShape::getArea() const { return 0.0; }
