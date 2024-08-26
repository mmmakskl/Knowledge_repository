#include <iostream>
#include <vector>
#include <exception>

void inArray(int ** array, std::size_t nRows, std::size_t nCols);
void outArray(int ** array, std::size_t nRows, std::size_t nCols);
void inStArray(std::vector<std::vector<int>> &matrix, std::size_t rows, std::size_t cols);
void outStArray(std::vector<std::vector<int>> &matrix, std::size_t rows, std::size_t cols);
void getMaxOfArray(std::vector<std::vector<int>> &matrix, std::size_t nElements);
void getNumberOfOrderedRows(int ** array, std::size_t nRows, std::size_t nCols);
bool isOrderedArray(int * inner, std::size_t nCols);
void arithmeticMeansOfPositive(int** matrix, std::vector<double> &vec, std::size_t rows, std::size_t columns);

int main()
{
	setlocale(LC_ALL, "Russian");

	std::size_t nRows = 0, nCols = 0;
	const std::size_t sRows = 3, sCols = 4;
	std::vector<std::vector<int>>stableArray (nRows, std::vector<int>(nCols));

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
	size_t nElements = sRows * sCols;

	std::cout << "Введите элементы статической матрицы, размерностью " << sRows << " строк, на " << sCols << " столбцов: \n";
	try
	{
		inStArray(stableArray, sRows, sCols);
	}
	catch(const std::exception)
	{
		std::cerr << "Invalid input!" << std::endl;
		return 1;
	}
	std::cout << std::endl;
	outStArray(stableArray, sRows, sCols);
	std::cout << std::endl;
	std::cout << "Максимальное значение элемента матрицы: ";
	getMaxOfArray(stableArray, nElements);
	std::cout << std::endl;

	std::cout << "Введите элементы динамической матрицы, размерностью " << nRows << " строк, на " << nCols << " столбцов: \n";
	try
	{
		inArray(array, nRows, nCols);
	}
	catch(const std::exception)
	{
		std::cerr << "Invalid input!" << '\n';
		return 1;
	}
	std::cout << std::endl;
	outArray(array, nRows, nCols);
	std::cout << std::endl;
	std::cout << "Строк идущих по возрастанию: ";
	getNumberOfOrderedRows(array, nRows, nCols);
	if(nRows > 0 || nCols > 0)
	{
		std::cout << std::endl << "Среднее арифмитическое каждой строки: \n";
	}
	std::vector<double> vec;
    try
	{
        arithmeticMeansOfPositive(array, vec, nRows, nCols);

        for (int i = 0; i < nRows; i++)
		{
            std::cout << i+1 << " - " << vec[i] << "\n";
        }
        std::cout << std::endl;
    }
	catch (std::exception)
	{
        std::cerr << "Невозможно построить вектор" << std::endl;
		return 1;
    }

	for (std::size_t i = 0; i < nRows; i++)
	{
		delete [] array[i];
	}
	delete [] array;
	return 0;
}

void inStArray(std::vector<std::vector<int>> &matrix, std::size_t rows, std::size_t cols)
{
    matrix.resize(rows, std::vector<int>(cols));

    for (std::size_t i = 0; i < rows; i++)
	{
        for (std::size_t j = 0; j < cols; j++)
		{
            std::cin >> matrix[i][j];
			if (std::cin.fail())
			{
				throw std::exception();
			}
        }
    }
}


void inArray(int ** array, std::size_t nRows, std::size_t nCols)
{
	for (std::size_t i = 0; i < nRows; i++)
	{
		for (std::size_t j = 0; j < nCols; j++)
		{
			std::cin >> array[i][j];
			if(std::cin.fail())
			{
				throw std::exception();
			}
		}
	}
}

void outStArray(std::vector<std::vector<int>> &matrix, std::size_t rows, std::size_t cols)
{
    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < cols; j++)
		{
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void outArray(int ** array, std::size_t nRows, std::size_t nCols)
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

void getMaxOfArray(std::vector<std::vector<int>> &matrix, std::size_t nElements)
{
	int max = 0;
	for (std::size_t i = 0; i < size(matrix); i++)
	{
		for (std::size_t j = 0; j < size(matrix[i]); j++)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
			}
		}
	}
	std::cout << max;
}

void getNumberOfOrderedRows(int ** array, std::size_t nRows, std::size_t nCols)
{
	std::size_t count = 0;
	for(std::size_t i = 0; i < nRows; i++)
	{
		int * inner = array[i];
		if(isOrderedArray(inner, nCols) == true)
		{
			count++;
		}
	}
	std::cout << count;
}

bool isOrderedArray(int * inner, std::size_t nCols)
{
	for(std::size_t i = 1; i < nCols; i++)
	{
		if(inner[i-1] > inner[i])
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void arithmeticMeansOfPositive(int** matrix, std::vector<double> &vec, std::size_t rows, std::size_t columns)
{
    if (rows == 0 || columns == 0)
	{
        throw std::exception();
    }

    for (std::size_t i = 0; i < rows; i++)
	{
        double sum = 0;
        std::size_t count = 0;
        for (std::size_t j = 0; j < columns; j++)
		{
            if (matrix[i][j] > 0)
			{
                sum += matrix[i][j];
                count++;
            }
        }
        if (count != 0)
		{
            vec.push_back(sum / count);
        }
		else
		{
            vec.push_back(0);
        }
    }
}
