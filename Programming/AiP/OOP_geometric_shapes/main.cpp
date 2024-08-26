#include "Rectangle.hpp"
#include "Ring.hpp"
#include "CompositeShape.hpp"
#include <iomanip>

void printShapeInfo(const Shape& shape)
{
    std::cout << std::setprecision(1) << std::fixed;
    const FrameRectangle frame = shape.getFrameRectagle();
    const double area = shape.getArea();
    const Point leftBottom(frame.getPos().getX() - frame.getWidth()/2, frame.getPos().getY() - frame.getHeight()/2);
    const Point rightTop(leftBottom.getX() + frame.getWidth(), leftBottom.getY() + frame.getHeight());
    std::cout << shape.getName() << " " << area << " " <<leftBottom.getX() << " " << leftBottom.getY() << " " << rightTop.getX() << " " << rightTop.getY() << std::endl;
}

void printCompositeShapeInfo(const Shape& shape)
{
    std::cout << std::setprecision(1) << std::fixed;

    const FrameRectangle frame = shape.getFrameRectagle();

    const Point leftBottom(frame.getPos().getX() - frame.getWidth()/2.0, frame.getPos().getY() - frame.getHeight()/2.0);
    const Point rightTop(leftBottom.getX() + frame.getWidth(), leftBottom.getY() + frame.getHeight());

    std::cout << shape.getName() << " " <<leftBottom.getX() << " " << leftBottom.getY() << " " << rightTop.getX() << " " << rightTop.getY() << std::endl;
}

int main()
{
    /*Test A1*/

    std::cout << "Test A1" << std::endl;
    {
        try
        {
            std::cout << "Creating ring and rectangle objects:\n";
            Ring ring(Point(1, 2), 6, 4);
            Rectangle rectangle(Point(1, 1), Point(10, 13));
            printShapeInfo(ring);
            printShapeInfo(rectangle);

            std::cout << "\nring.move(1, -2) and rectangle.move(-3, 3):\n";
            ring.move(1, -2);
            rectangle.move(-3, 3);
            printShapeInfo(ring);
            printShapeInfo(rectangle);

            std::cout << "\nRing move Point(10, -20) and rectangle move Point(4, 7):\n";
            ring.move(Point(10, -20));
            rectangle.move(Point(4, 7));
            printShapeInfo(ring);
            printShapeInfo(rectangle);

            std::cout << "\nCloned ring and recrangle:\n";
            Shape* clonedRing = ring.clone();
            Shape* clonedRectangle = rectangle.clone();
            printShapeInfo(*clonedRing);
            printShapeInfo(*clonedRectangle);

            delete clonedRing;
            delete clonedRectangle;
        }
        catch(char const* exp)
        {
            std::cout << "Exception: " << exp << std::endl;
            std::cout << "Program terminated" << std::endl;
        }
        std::cout << std::endl;
    }

    /*Test A2*/

    std::cout << "Test A2" << std::endl;
    {
        try
        {
            std::cout << "Creating ring and rectangle objects:\n";
            Rectangle rectangle(Point(0, 0), Point(9, 17));
            Ring ring(Point(9, -9), 10, 5);
            printShapeInfo(ring);
            printShapeInfo(rectangle);

            std::cout << "\nring.move(-12, 23) and rectangle.move(-25, 25):\n";
            rectangle.move(-25, 25);
            ring.move(-12, 23);
            printShapeInfo(ring);
            printShapeInfo(rectangle);

            std::cout << "\nRing move Point(2, -4) and rectangle move Point(9, 10):\n";
            ring.move(Point(2, -4));
            rectangle.move(Point(9, 10));
            printShapeInfo(ring);
            printShapeInfo(rectangle);

            std::cout << "\nring.scale(2) and rectangle.scale(2):\n";
            rectangle.scale(2);
            ring.scale(2);
            printShapeInfo(ring);
            printShapeInfo(rectangle);
        }
        catch(char const* exp)
        {
            std::cout << "Exception: " << exp << std::endl;
            std::cout << "Program terminated" << std::endl;
        }
        std::cout << std::endl;
    }

    /*Test A3*/

    std::cout << "Test A3" << std::endl;
    {
        try
        {
            std::cout << "Creating composite shape:" << std::endl;
            CompositeShape composite(3);
            Rectangle* rectangle = new Rectangle(Point(0.0, 0.0), Point(3.0, 4.0));
            Ring* ring = new Ring(Point(1.0, 2.0), 2, 6);
            Rectangle* rectangle2 = new Rectangle(Point(2.0, 3.0), Point(7.0, 9.0));
            composite.push_back(rectangle);
            composite.push_back(ring);
            composite.push_back(rectangle2);
            printCompositeShapeInfo(composite);

            std::cout << "\nComposite shape move(-23, 45):" << std::endl;
            composite.move(-23, 45);
            printCompositeShapeInfo(composite);

            std::cout << "\nComposite shape move Point(-10, 15):" << std::endl;
            composite.move(Point(-10, 15));
            printCompositeShapeInfo(composite);

            std::cout << "\nCreating clone composite shape:"  << std::endl;
            Shape* clonedComposite = composite.clone();
            printCompositeShapeInfo(*clonedComposite);

            std::cout << "\nCloned composite shape scale(4) and composite shape scale(3):" << std::endl;
            clonedComposite->scale(4);
            composite.scale(3);
            std::cout << "Cloned ";
            printCompositeShapeInfo(*clonedComposite);
            printCompositeShapeInfo(composite);

            delete clonedComposite;
        }
        catch(char const* exp)
        {
            std::cout << "Exception: " << exp << std::endl;
            std::cout << "Program terminated" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
