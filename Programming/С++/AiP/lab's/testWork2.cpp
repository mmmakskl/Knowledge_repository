#include <iostream>

const size_t SIZE = 4;

void inArray(int array[SIZE][SIZE], std::size_t rows, std::size_t cols);
void outArray(int array[SIZE][SIZE], std::size_t rows, std::size_t cols);
void positiveStaticRows(int array[SIZE][SIZE], std::size_t rows, std::size_t cols);
void inDinArray(int ** array, std::size_t nRows, std::size_t nCols);
void outDinArray(int ** array, std::size_t nRows, std::size_t nCols);
void positiveDinamicRows(int ** array, std::size_t nRows, std::size_t nCols);

int main()
{
	setlocale(LC_ALL, "russian");
	std::size_t nRows = 0, nCols = 0;
	const std::size_t sRows = 3, sCols = 4;
	int staticArray[SIZE][SIZE]{0};
	std::cout << "Введите размерность динамической матрицы, количество строк X количество столбцов \n";
	std::cin >> nRows >> nCols;
	if (std::cin.fail() || nRows < 0 || nCols < 0)
	{
		std::cerr << "Invalid input!";
		return 1;
	}

	int **array = new int * [nRows];
	for (int i = 0; i < nRows; i++)
	{
		array[i] = new int[nCols];
	}
	std::cout << "Введите элементы статической матрицы: \n";
	try
	{
		inArray(staticArray, SIZE, SIZE);
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	outArray(staticArray, SIZE, SIZE);
	std::cout << "\n Количество положительных строк: \n";
	positiveStaticRows(staticArray, SIZE, SIZE);

	std::cout << "\n Введите элементы динамической матрицы: \n";
	try
	{
		inDinArray(array, nRows, nCols);
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	outDinArray(array, nRows, nCols);
	std::cout << "\n Количество положительных строк: \n";
	positiveDinamicRows(array, nRows, nCols);

	for (std::size_t i = 0; i < nRows; i++)
	{
		delete [] array[i];
	}
	delete [] array;
	return 0;
}

void inArray(int array[SIZE][SIZE], std::size_t rows, std::size_t cols)
{
	for (std::size_t i = 0; i < rows; i++)
	{
		for (std::size_t j = 0; j < cols; j++)
		{
			std::cin >> array[i][j];
			if(std::cin.fail())
			{
				throw std::invalid_argument("Input : ERROR");
			}
		}
	}
}

void inDinArray(int ** array, std::size_t nRows, std::size_t nCols)
{
	for (std::size_t i = 0; i < nRows; i++)
	{
		for (std::size_t j = 0; j < nCols; j++)
		{
			std::cin >> array[i][j];
			if(std::cin.fail())
			{
				throw std::invalid_argument("Input : ERROR");
			}
		}
	}
}

void positiveStaticRows(int array[SIZE][SIZE], std::size_t rows, std::size_t cols)
{
	int count = 0;
	bool positive = true;
	for (size_t i = 0; i < rows; i++)
	{
		positive = true;
		for (size_t j = 0; j < cols; j++)
		{
			if (array[i][j] <= 0)
			{
				positive = false;
				break;
			}

		}
		if (positive)
		{
			count++;
		}
	}
	std::cout << count;
}

void positiveDinamicRows(int ** array, std::size_t nRows, std::size_t nCols)
{
	int count = 0;
	bool positive = true;
	for (size_t i = 0; i < nRows; i++)
	{
		positive = true;
		for (size_t j = 0; j < nCols; j++)
		{
			if (array[i][j] <= 0)
			{
				positive = false;
				break;
			}

		}
		if (positive)
		{
			count++;
		}
	}
	std::cout << count;
}

void outDinArray(int ** array, std::size_t nRows, std::size_t nCols)
{
	for (std::size_t i = 0; i < nRows; i++)
	{
		for (std::size_t j = 0; j < nCols; j++)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void outArray(int array[SIZE][SIZE], std::size_t rows, std::size_t cols)
{
	for (std::size_t i = 0; i < rows; i++)
	{
		for (std::size_t j = 0; j < cols; j++)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
