#include <iostream>
#include <fstream>

const std::string ERROR_OPEN_FILE = "Unable to find or open the file";
const std::string ERROR_NOT_NUMBER = "The maximum length of a string is not specified by a number or integer";
const std::string ERROR_NOT_POSITIVE_NUMBER = "The maximum string length is specified by a non-positive number";

const std::string IN_FILE = "in.txt";
const std::string OUT_FILE = "out.txt";

char* createDuplicateCharactersString(char* destination, const char* source);

template<typename T>
void checkOpenFile(T& stream);

int main()
{
	std::size_t lenght = 0;
	std::ifstream in;
	std::ofstream out;

	try
	{
		in.open(IN_FILE);
		checkOpenFile(in);

		in >> lenght;
		if (in.fail() || in.peek() != '\n')
		{
			throw ERROR_NOT_NUMBER;
		}
		if (lenght <= 0)
		{
			throw ERROR_NOT_POSITIVE_NUMBER;
		}
	}
	catch (const std::string err)
	{
		std::cerr << err << '\n';
		in.close();
		return EXIT_FAILURE;
	}

	char* strFileIn1 = nullptr;
	char* strFileIn2 = nullptr;
	try
	{
		strFileIn1 = new char[lenght] {0};
		in >> strFileIn1;
		in.close();

		std::cout << "Maximum line length: " << lenght << std::endl;
		std::cout << "Source string: ";
		std::size_t i = 0;
		while (strFileIn1[i] != '\0')
		{
			std::cout << strFileIn1[i];
			i++;
		}
	}
	catch (const std::exception ex)
	{
		std::cerr << ex.what() << std::endl;
		in.close();
		delete[] strFileIn1;
		return EXIT_FAILURE;
	}

	char* strFileOut1 = nullptr;
	char* strFileOut2 = nullptr;
	try
	{
		strFileOut1 = new char[lenght] {0};
		strFileOut2 = new char[lenght] {0};
		std::cout << std::endl << "The string is formed from repeating characters of the original string: " << createDuplicateCharactersString(strFileOut1, strFileIn1) << std::endl;
	}
	catch (const std::exception ex)
	{
		std::cerr << ex.what() << std::endl;
		delete[] strFileIn1;
		delete[] strFileOut1;
		return EXIT_FAILURE;
	}

	try
	{
		out.open(OUT_FILE);
		checkOpenFile(out);
		out << "The string is formed from repeating characters of the original string: " << strFileOut1 << std::endl;
		delete[] strFileIn1;
		delete[] strFileOut1;
		out.close();
	}
	catch (const std::string err)
	{
		std::cerr << err;
		delete[] strFileIn1;
		delete[] strFileOut1;
		out.close();
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

template<typename T>
void checkOpenFile(T& stream)
{
	if (!stream) {
		throw ERROR_OPEN_FILE;
	}
}

char* createDuplicateCharactersString(char* destination, const char* source)
{
	char value = '0';
	std::size_t i = 0;
	std::size_t order = 0;
	while (source[i] != '\0')
	{
		value = source[i];
		int count = 0;
		std::size_t j = 0;
		while (source[j] != '\0')
		{
			if (value == source[j])
			{
				count++;
			}
			j++;
		}
		if (count > 1)
		{
			std::size_t k = 0;
			bool isTrue = 1;
			while (destination[k] != '\0')
			{
				if (value == destination[k])
				{
					isTrue = 0;
					break;
				}
				k++;
			}
			if (isTrue == 1)
			{
				destination[order] = value;
				order++;
			}
		}
		i++;
	}
	return destination;
}
