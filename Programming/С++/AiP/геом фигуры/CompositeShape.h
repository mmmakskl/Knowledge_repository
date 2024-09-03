#pragma once
#include"Classes.h"
#include<vector>
const std::string ERROR_OF_SIZE = "Достигнут максимальный размер массива.Элемент не может быть добавлен\n";

class CompositeShape
{
private:
	std::vector <Shape*> arr;
	int maxCount;
public:
	CompositeShape();
	~CompositeShape();
	void scale(const double k);
	void move(const Point &point);
	void add( Shape& figure);
	FrameRectangle& getFrameRectangle()const;
	void countOfTypes() const;
};
void getInfo( CompositeShape& figure);