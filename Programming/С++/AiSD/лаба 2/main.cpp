#include "Stack.h"
#include"Queue.h"
#include"Functions.h"

const std::string ERRROR_OF_INPUT = "Ошибка ввода\n";

int main()
{
	setlocale(LC_ALL, "ru");
	
	try
	{
		{
			std::cout << "__________________Stack(int)__________________\n\n";
			std::cout << "Введите количество элементов стека:\t";
			std::string size="";
			std::cin >> size;
			StackArray<int> stack(size);
			int cnt = 0;
			std::string value = "";
			while (cnt < std::stoi(size))
			{
				std::cout << "Введите элемент:\t";
				std::cin >> value;
				checkInput(value) ? stack.push(std::stoi(value)) :  throw std::invalid_argument(ERRROR_OF_INPUT);
				cnt++;
			}
			stack.print();
			std::cout << "Удаление элемента:\t"<<stack.pop()<<"\n";
			stack.print();
			stack.isEmpty() ? std::cout << "Stack пуст\n" : std::cout << "В Stack есть элементы\n";
		}

		{
			std::cout << "\n__________________Queue(int)__________________\n\n";;
			std::cout << "Введите количество элементов очереди:\t";
			std::string size = "";
			std::cin >> size;
			CircularQueue<int> queue(size);
			int cnt = 0;
			std::string value = "";
			while (cnt < std::stoi(size))
			{
				std::cout << "Введите элемент:\t";
				std::cin >> value;
				checkInput(value) ? queue.enQueue(std::stoi(value)) : throw std::invalid_argument(ERRROR_OF_INPUT);
				cnt++;
			}
			queue.print();
			std::cout << "Удаление элемента:\n";
			queue.deQueue();
			queue.print();
			queue.print();
			queue.isEmpty() ? std::cout << "Очередь пуст\n" : std::cout << "В очереди есть элементы\n";
		}
		std::cout << "\n______________checkBalanceBrackets_____________\n\n";
		std::cout << "Введите выражение для проверки соответсвия скобок:\t";
		std::string  text = "";
		std::cin >> text;
		std::cout << "Введите максимальную глубину вложенности скобок:\t";
		int maxDeep = 0;
		std::cin >> maxDeep;
		checkBalanceBrackets(text, maxDeep) ? std::cout << "Результат:  Соответствует\n" : std::cout << "Результат:  Не соотвествует\n";
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
