#pragma once
#include<string>
#include<iostream>
#include <cstring>
#include <vector>
const std::string ERROR_OF_INDEX = "Индекс вне границ массива";

class String
{
	friend std::ostream& operator << (std::ostream& stream, String& str);
public:
	String();
	String(const char* str);
	String(const String& str) ;
	String(String&& str)noexcept;
	~String();
	String& operator = (const char* str);
	String& operator = (String && str) noexcept;
	char& operator[] (size_t pos);
	String& append(const String& str);
	String& operator+ (const String& str);
	String& insret(size_t pos, const char* str);
	int compare(const String& str);
private:
	size_t size, capacity;
	std::vector <char>* pointer;
	std::vector <char> c_str;
};

void testingString();