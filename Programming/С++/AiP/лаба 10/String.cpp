#include "String.h"


String::String() 
{
	size = 0;
	capacity = 0;
	pointer = nullptr;
};
String::String(const char* str)
{
	size = strlen(str);
	capacity = size + 1;
	for (int i = 0; i < size; i++)
		c_str.push_back(str[i]);
	c_str.push_back('\0');
	pointer = &c_str;
}
String::String(const String& str) 
{
	size = str.size;
	capacity = str.capacity;
	pointer = str.pointer;
}
String::String(String&& str)noexcept
{
	size = str.size;
	capacity = str.capacity;
	pointer = str.pointer;
	str.size = 0;
	str.capacity = 0;
	str.pointer = nullptr;
};
String::~String() {}
String& String::operator=(const char* str)
{
	size = strlen(str);
	capacity = size + 1;
	for (int i = 0; i < size; i++)
		c_str.push_back(str[i]);
	c_str.push_back('\0');
	pointer = &c_str;
	return *this;
}
String& String::operator=(String&& str) noexcept
{
	size = str.size;
	capacity = str.capacity;
	pointer = str.pointer;
	str.size = 0;
	str.capacity = 0;
	str.pointer = nullptr;
	return *this;
}
char& String::operator[](size_t pos)
{
	if (pos < 0 || pos >= size) throw std::runtime_error(ERROR_OF_INDEX);
	else return (*pointer).at(pos);
}

String& String::append(const String& str)
{
	size += str.size;
	capacity = size +1;
	(*pointer).pop_back();
	for (char element : *str.pointer)
		(*pointer).push_back(element);
	return *this;
}

String& String::operator+(const String& str)
{
	size += str.size;
	capacity = size + 1;
	(*pointer).pop_back();
	for (char element : *str.pointer)
		(*pointer).push_back(element);
	return *this;
}

String& String::insret(size_t pos,const  char* str)
{
	if (0 > pos || pos >= size) throw std::runtime_error(ERROR_OF_INDEX);
	else 
	{
		size += strlen(str);
		capacity = size + 1;
		auto it = pointer->begin() + pos;
		for (int i = 0; i < strlen(str); i++)
		{
			pointer->insert(it, str[i]);
			it = pointer->begin()+pos+1;
		}
	return *this;
	}
}

int String::compare(const String& str)
{
	int i = 0;
	int result = 0;
	while (i != size || i != str.size)
	{
		if (pointer->at(i) < str.pointer->at(i)) { result = -1; break; }
		if (pointer->at(i) > str.pointer->at(i)) { result = 1; break; }
		i++;
	}
	return result;
}

std::ostream& operator<<(std::ostream& stream, String& str)
{
	stream << "size:  " << str.size << "\tcapacity:  " << str.capacity;
	if (str.pointer != nullptr)
	{
		stream << "\nСтрока:  ";
		for (char value : *str.pointer)
			//if (value!='\0')
			stream << value;
	}
	else stream << "\n";
	stream << "\n";
	return stream;
}

void testingString()
{
	String str;
	std::cout << "Конструктор по умолчанию:\t" << str;
	String str1("string1");
	std::cout << "Конструктор с параметрами:\t" << str1;
	String str2(str1);
	std::cout << "Конструктор копирования:\t" << str2;
	str = std::move(str1);
	std::cout << "Конструктор перемещения:\t" << str << "Перемещаемая строка\t" << str1;
	str = std::move(str2);
	std::cout << "Присваивание с перемещением:\t" << str << "Перемещаемая строка\n" << str2;
	str2 = "str2";
	str = "str";
	std::cout << "Присваивание\nstr:  " << str << "str2:  " << str2;
	std::cout << "1 элемент в каждой из строк:\nstr[1]= " << str[1] << "\tstr2[1]= " << str2[1] << "\n\n";
	str.append(str2);
	std::cout << "Конкатенация str и str2;\n str: " << str << "str2: " << str2;
	str2 + str;
	std::cout << "Конкатенация str2 и str;\n str2: " << str2 << "str: " << str;
	str2.insret(2, "))");
	std::cout << "Вставка подстроки:\nstr2:  " << str2;
	std::cout << "str2 > str\t" << str2.compare(str) << "\n";
}
