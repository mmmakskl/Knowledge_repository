#include"Classes.h"
#include"CompositeShape.h"

int main()
{
	Shape* clone =nullptr;
	try
	{
		setlocale(LC_ALL, "ru");
		cout << "Тестирование класса Square\n\n";
		Shape* figure;
		Square square;
		getInfo(square);
		figure = &square;
		cout << "Объект класса Shape:\n";
		getInfo(*figure);
		cout << "Координаты нового цетра\n";
		Point point;
		cin >> point;
		square.move(point);
		getInfo(square);
		cout << "Ширина ограничивающего прямоугольника: " << square.getFrameRectangle().getWidth()
			<< "\nВысота ограничивающего прямоугольника: " << square.getFrameRectangle().getHeight();
		cout << "\nОбъект класса Shape:\n";
		getInfo(*figure);
		cout << "Ширина ограничивающего прямоугольника: " << figure->getFrameRectangle().getWidth()
			<< "\nВысота ограничивающего прямоугольника: " << figure->getFrameRectangle().getHeight();
		std::string k;
		cout << "\nКоэффициент изотропного масштабировани (>0) = ";
		cin >> k;
		square.scale(inputToDouble(k));
		getInfo(square);
		cout << "Объект класса Shape:\n";
		getInfo(*figure);
		clone = square.clone();
		cout << "Создание копии объекта Square\n";
		getInfo(*clone);
		delete clone;
		clone = nullptr;
		cout << "------------------------------------------------------\n\n";
		cout << "Тестирование класса Concave\n\n";
		Concave concave;
		getInfo(concave);
		figure = &concave;
		cout << "Объект класса Shape:\n";
		getInfo(*figure);
		cout << "Координаты нового центра\n";
		cin >> point;
		concave.move(point);
		getInfo(concave);
		cout << "Ширина ограничивающего прямоугольника: " << concave.getFrameRectangle().getWidth()
			<< "\nВысота ограничивающего прямоугольника: " << concave.getFrameRectangle().getHeight();
		cout << "\nОбъект класса Shape:\n";
		getInfo(*figure);
		cout << "Ширина ограничивающего прямоугольника: " << figure->getFrameRectangle().getWidth()
			<< "\nВысота ограничивающего прямоугольника: " << figure->getFrameRectangle().getHeight();
		cout << "\nКоэффициент изотропного масштабировани (>0) = ";
		cin >> k;
		concave.scale(inputToDouble(k));
		getInfo(concave);
		cout << "Объект класса Shape:\n";
		getInfo(*figure);
		clone = concave.clone();
		cout << "Создание копии объекта Square\n";
		getInfo(*clone);
		delete clone;
		clone = nullptr;
		cout << "------------------------------------------------------\n\n";
		cout << "Тестирование класса CompositeShape\n";
		CompositeShape figures;
		cout << "Добавление элементов\nY - продолжение ввода\nN - завершение ввода\n";
		char flag = 'Y';
		while (flag != 'N' && flag == 'Y')
		{
				char choice;
				cout << "Какую фигуру добавим?\n1-Square\n2-Concave\nВыбор: ";
				cin >> choice;
				switch (choice)
				{
				case '1': figures.add(*new Square());
					break;
				case '2': figures.add(*new Concave());
					break;
				default: throw std::invalid_argument(ERROR_OF_INPUT);
				}
				cout << "Продолжим добавлять фигуры? ";
				cin >> flag;
				if (flag != 'Y' && flag != 'N') throw std::runtime_error(ERROR_OF_INPUT);
		}
		getInfo(figures);
		cout << "Координаты нового центра\n";
		cin >> point;
		figures.move(point);
		getInfo(figures);
		cout << "\nКоэффициент изотропного масштабировани (>0) = ";
		cin >> k;
		figures.scale(inputToDouble(k));
		getInfo(figures);
	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << ex.what() << std::endl;
		if (clone != nullptr) delete clone;
		return EXIT_FAILURE;
	}
	catch (std::runtime_error& ex)
	{
		std::cerr << ex.what() << std::endl;
		if (clone != nullptr) delete clone;
		return EXIT_FAILURE;
	}
	return 0;
}