#include"Point.h"
#include"Triangle.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Point a(3, 4);
	Point b(4, 5);
	b = a;
	try {
		//тестироание класса Point

		Point A; // вызов конструктора без параметров
		std::cout << "A = ";
		output(A);
		Point B (3.5, 5); // вызов конструктора с параметрами
		std::cout << "B = ";
		output(B);
		Point C(A); // вызов конструктора копирования
		std::cout << "C = ";
		output(C);
		std::cout << "Расстояние от А до В = " << A.getDistance(B) << "\nРасстояние от А до С = " << A.getDistance(C) << "\n";
		A.isEqual(B) ? std::cout << "Точки A и B совпадают\n" : std::cout << "Точки A и B не совпадают\n";
		std::string value = "";
		std::cout << "Растояние, на которое будет перемещена точка = \t";
		std::cin >> value;
		if (checkInput(value)) A.move(std::stod(value));
		std::cout << "A = ";
		output(A);
		std::cout << "Введите радиус окружности = \t";
		std::cin >> value;
		if (checkInput(value))	iSpointInCircle(A, std::stod(value));
		A.setX(0);
		A.setY(0);
		std::cout << "Введите последовательность точек, признак конца последовательности точка(0,0)\n";
		Point temp;
		Point point_min;
		input(temp);
		double min_distance = temp.getDistance(A);
		point_min = temp;
		while ( temp.getX()!=0 || temp.getY()!=0)
		{
			if (min_distance >= temp.getDistance(A))
			{
				min_distance = temp.getDistance(A);
				point_min = temp;
			}
			input(temp);
		}
		if (min_distance == 0) std::cout<<"количество точек равно 0\n";
		else
		{
			std::cout << "Точка ближайщая к началу координат: ";
			output(point_min);
		}
	

		//тестирование класса Triangle
		std::cout << "точка А:\n";
		input(A);
		std::cout << "точка B:\n";
		input(B);
		std::cout << "точка C:\n";
		input(C);
		Triangle ABC(A, B, C); //вызов конструктора с параметрами
		std::cout << "координаты треугольника ABC:\n";
		output(ABC);
		Triangle ABC_1; // вызов конструктра без параметров
		std::cout << "координаты треугольника ABC_1:\n";
		output(ABC_1);
		std::cout << "координаты треугольника ABC_1:\n";
		ABC_1.setA(ABC.getB());
		output(ABC_1);
		Triangle ABC_2(ABC); //вызов конструктора копирования
		std::cout << "координаты треугольника ABC_2:\n";
		output(ABC_2);
		ABC.isTriangle() ? std::cout << "ABC треугольник\n" : std::cout << "ABC не треугольник\n";
		std::cout << "Растояние, на которое будет перемещен треугольник = \t";
		std::cin >> value;
		if (checkInput(value)) ABC.move(std::stod(value));
		output(ABC);
		std::cout << "Периметр ABC = "<< ABC.getPerimeter()<<"\n";
		ABC.isEqual(ABC_2) ? std::cout << "Теугольники АВС и АВС_1 равны\n" : std::cout<< "Теугольники АВС и АВС_2 не равны\n";
		isEqualSquare(ABC, ABC_2);

	}
	catch (std::runtime_error& ex)
	{
		std::cerr << ex.what()<<"\n";
		exit(EXIT_FAILURE);
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what() << "\n";
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
