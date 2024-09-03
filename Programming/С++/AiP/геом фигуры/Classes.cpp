#include "Classes.h"

double inputToDouble(std::string& value)
{
	std::regex regular("-?\\d+,?\\d*");
	std::regex replace("\\.");
	value = std::regex_replace(value, replace, ",");
	if (std::regex_match(value, regular)) return std::stod(value);
	else throw std::invalid_argument(ERROR_OF_INPUT);
}

// класс Point
Point::Point() { x_ = 0; y_ = 0; }
Point::Point(double x, double y) { x_ = x; y_ =y; }
Point::Point(const Point& point) { x_ = point.x_; y_ = point.y_; }
Point::~Point() {}

double Point::getDistance(const Point& point)const 
{
	return sqrt(pow(x_-point.x_,2) + pow(y_-point.y_,2));
}

Point &Point::operator=(const Point *point)
{
	x_ = point->x_;
	y_ = point->y_;
	return *this;
}

Point &Point::operator+(const double value) const 
{
	Point point;
	point.x_ = x_ + value;
	point.y_ = y_ + value;
	return point;
}
Point& Point::operator+(const Point &point)
{
	x_ += point.x_;
	y_ += point.y_;
	return *this;
}
Point& Point::operator-(const double value) const
{
	Point point;
	point.x_ = x_ - value;
	point.y_=y_ - value;
	return point;
}
Point& Point::operator-(const Point& point)
{
	x_ -= point.x_;
	y_ -= point.y_;
	return *this;
}
Point& Point:: operator * (const double value)
{
	x_ *= value;
	y_ *= value;
	return *this;
}
std::ostream& operator<<(std::ostream& stream, const Point& point)
{
	stream << point.x_ << " " << point.y_ << " ";
	return stream;
}

std::istream& operator>>(std::istream& stream,  Point& point)
{
	std::string value;
	cout << "Введите координаты точек\nx = ";
	stream >> value;
	point.x_ = inputToDouble(value);
	cout << "y = ";
	stream >> value;
	point.y_ = inputToDouble(value);
	return stream;
}

//класс FrameRectangle
FrameRectangle::~FrameRectangle() {}

FrameRectangle::FrameRectangle(double width, double height, Point pos)
{
	width_ = width;
	height_ = height;
	pos_ = pos;
}

Point FrameRectangle::getLeftDown() const
{
	Point leftDown (pos_.x_ - width_ /2, pos_.y_ - height_/2);
	return leftDown;
}

Point FrameRectangle::getRightTop() const
{
	Point rightTop(pos_.x_ + width_ / 2, pos_.y_ + height_ / 2);
	return rightTop;
}

Point FrameRectangle::getMiddle() const{	return pos_;}

double FrameRectangle::getHeight() const {return height_;}

double FrameRectangle::getWidth() const {	return width_;}



// класс Square
Square::Square() 
{
	std::string value;
	cout << "Сторона квадрата = ";
	cin >> value;
	if (inputToDouble(value) > 0) length_ = inputToDouble(value);
	else throw std::invalid_argument(ERROR_OF_INPUT);
	cin >> A_;
	middle_ = A_ + 0.5 * length_;
}

Square::Square(const Square& sq)
{
	length_ = sq.length_;
	A_ = sq.A_;
	middle_ = sq.middle_;
}

Square::~Square() {};

Square& Square::operator=(const Square& square)
{
	A_ = square.A_;
	length_ = square.length_;
	middle_ = square.middle_;
	return *this;
}

void Square::scale(double k)
{
	if (k <= 0) throw std::invalid_argument(ERROR_OF_INPUT);
	else 
	{
		length_ = length_ * k;
		A_ = middle_ - length_ * k/2;
	}
}

double Square::getArea() const{	return length_*length_;}

//ограничивающий прямогульник квадрата совпадает с самим квадратом
FrameRectangle Square::getFrameRectangle()const
{
	FrameRectangle rectangle(length_,length_, middle_);
	return rectangle;
}

void Square::move(const double x, const double y)
{
	middle_.x_ = middle_.x_ + x;
	middle_.y_ = middle_.y_ + y;
	A_.x_ = A_.x_ +x;
	A_.y_ = A_.y_ + y;
}

void Square::move( const Point &point)
{
	middle_ = point;
	A_ = middle_ - length_/2;
}

Shape* Square::clone()  { return new Square(*this);}

std::string Square::getName() const{return "SQUARE";}

Point Square::getMiddle() const {	return middle_;}

bool isTriangle(const Point& A, const Point& B, const Point& C)
{
	double AB = A.getDistance(B);
	double BC = B.getDistance(C);
	double AC = A.getDistance(C);
	return (AB + BC > AC) && (BC + AC > AB) && (AC + AB > BC);
}

float getSquare(const Point& A, const Point& B, const Point& C)
{
	if (isTriangle(A, B, C))
	{
		double AB = A.getDistance(B);
		double BC = B.getDistance(C);
		double AC = A.getDistance(C);
		double p = 0.5 * (AB + BC + AC);
		return  sqrt(p * (p - AB) * (p - BC) * (p - AC));
	}
	else throw std::runtime_error(ERROR_OF_FIGURE);
}
// класс Concave
Concave::Concave() 
{
	cin >> A_ >> B_ >> C_ >> D_;
	if (round(getSquare(A_, B_, C_)*10)/10 != round((getSquare(A_, B_, D_) + getSquare(B_, C_, D_) + getSquare(A_, C_, D_))*10)/10)
		throw std::runtime_error(ERROR_OF_FIGURE);
}

Concave::Concave(const Concave& cn)
{
	A_ = cn.A_;
	B_ = cn.B_;
	C_ = cn.C_;
	D_ = cn.D_;
}

Concave::~Concave(){}

double Concave::getArea() const
{
	return getSquare(A_,B_,D_) + getSquare(B_, C_, D_);
}

FrameRectangle Concave::getFrameRectangle()const
{
	double x_min = std::min(A_.x_,std::min( B_.x_, C_.x_));
	double x_max = std::max(A_.x_, std::max(B_.x_, C_.x_));
	double y_min = std::min(A_.y_, std::min(B_.y_, C_.y_));
	double y_max = std::max(A_.y_, std::max(B_.y_, C_.y_));
	Point rectangleMiddle((x_max+x_min)/2, (y_max + y_min)/2);
	FrameRectangle rectangle(x_max - x_min, y_max - y_min, rectangleMiddle);
	return rectangle;
}

void Concave::move(const Point& point)
{
	// перемещение верших
	Point move(point.x_ - D_.x_, point.y_ - D_.y_);
	A_ + move;
	B_ + move;
	C_ + move;
	D_ = point; //перемещение центра
}
void Concave::move(const double x, const double y)
{
	Point movement(x, y);
	D_ + movement;
	A_ + movement;
	B_ + movement;
	C_ + movement;
}

Shape* Concave::clone(){ return new Concave(*this); }

Concave& Concave::operator=(const Concave& triangle)
{
	A_ = triangle.A_;
	B_ = triangle.B_;
	C_ = triangle.C_;
	D_ = triangle.D_;
	return *this;
}

std::string Concave::getName() const {return "CONCAVE"; }

Point Concave::getMiddle() const{	return D_;}

void Concave::scale(double k)
{
	if (k <= 0) throw std::invalid_argument(ERROR_OF_INPUT);
	else
	{
		A_ = (A_ - D_) * k + D_;
		B_ = (B_ - D_) * k + D_;
		C_ = (C_ - D_) * k + D_;
	}
}

void getInfo(const Shape &figure)
{
	cout << std::setprecision(1) << std::fixed;
	cout<<figure.getName()<<" ";
	cout << figure.getArea() << " ";
	cout << figure.getFrameRectangle().getLeftDown();
	cout<< figure.getFrameRectangle().getRightTop()<<"\n";
}