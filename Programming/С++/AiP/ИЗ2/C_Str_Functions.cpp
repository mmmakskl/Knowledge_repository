#include "C_Str_Functions.h"

char* deleteDigitsFromStr(char *destination, const char *source)
{
	int i = 0;
	int j = 0;
	while (source[i] != '\0')
	{
		if (!isdigit(source[i]))
		{
			destination[j] = source[i];
			j++;
		}
		i++;
	}
	destination[j] = '\0';
	return destination;
}

char* convertToLowercase(char* destination, const char* source)
{

	int i = 0;
	while (source[i] != '\0')
	{
		if (isalpha(source[i]) && isupper(source[i]))
			destination[i] = tolower(source[i]);
		else destination[i] = source[i];
		i++;
	}
	destination [i] = '\0';
	return destination;
}

void showStr(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		std::cout << str[i];
		i++;
	}
	std::cout << "\n\n";
}

int checkInput(const std::string &value)
{
	std::regex regular ("\\d+");
	if (!std::regex_match(value, regular)) throw std::invalid_argument(ERROR);
	return stoi(value);
}
