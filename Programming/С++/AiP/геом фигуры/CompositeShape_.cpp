#include "CompositeShape.h"

CompositeShape::CompositeShape()
{
	std::string value;
	cout << "Максимальное количество элементов в составной фигуре = ";
	cin >> value;
	if (trunc(inputToDouble(value)) == inputToDouble(value) && inputToDouble(value) > 0) maxCount = inputToDouble(value);
	else throw std::runtime_error(ERROR_OF_INPUT);
}
CompositeShape::~CompositeShape()  
{
	for (auto figure : arr) delete figure;
}

void CompositeShape::scale(const double k)
{
	double a = getFrameRectangle().getMiddle().x_;
	double b = getFrameRectangle().getMiddle().y_;
	for (auto element : arr)
	{
		double x = k * (element->getMiddle().x_ - a);
		double y = k * (element->getMiddle().y_ - b );
		element->scale(k);
		element->move(x, y);
	}
}

void CompositeShape::move(const Point &point)
{
	double x = point.x_ - getFrameRectangle().getMiddle().x_;
	double y = point.y_ - getFrameRectangle().getMiddle().y_;
	for (auto element : arr) element->move(x,y);
}

void CompositeShape::add( Shape& figure)
{
	if (arr.size() < maxCount)  arr.push_back(&figure);
	else throw std::runtime_error(ERROR_OF_SIZE);
}

FrameRectangle& CompositeShape::getFrameRectangle()const
{
	double x_max , y_max;
		x_max=y_max=DBL_MIN;
	double x_min, y_min;
	x_min = y_min = DBL_MAX;
	for (auto element : arr)
	{
		x_max = std::max(element->getFrameRectangle().getRightTop().x_, x_max);
		y_max = std::max(element->getFrameRectangle().getRightTop().y_,y_max);
		x_min = std::min(element->getFrameRectangle().getLeftDown().x_, x_min);
		y_min = std::min(element->getFrameRectangle().getLeftDown().y_, y_min);
	}
	Point rectangleMiddle((x_max + x_min) / 2, (y_max + y_min) / 2);
	FrameRectangle rectangle(x_max - x_min, y_max - y_min, rectangleMiddle);
	return rectangle;
}

void CompositeShape::countOfTypes() const
{
	int count_square, count_concave;
	count_square = count_concave = 0;
	for (auto figure : arr)
	{
		if (figure->getName() == "SQUARE")count_square++;
		else count_concave++;
	}
	cout << "SQUARE = " << count_square << "  CONCAVE = " << count_concave << "\n";
}


void getInfo( CompositeShape& figure)
{
	cout << std::setprecision(1) << std::fixed;
	figure.countOfTypes();
	cout << figure.getFrameRectangle().getLeftDown();
	cout << figure.getFrameRectangle().getRightTop() << "\n";
}