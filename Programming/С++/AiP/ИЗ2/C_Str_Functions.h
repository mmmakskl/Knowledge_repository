#pragma once
#include<iostream>
#include<regex>
#include<string>


const std::string ERROR = "Некорректный ввод";

char * deleteDigitsFromStr(char *destination, const char *source);

char* convertToLowercase(char* destination, const char* source);

void showStr(const char* str);

int checkInput( const std::string &value);