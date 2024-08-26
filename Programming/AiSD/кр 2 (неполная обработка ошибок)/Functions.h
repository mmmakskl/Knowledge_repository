#pragma once
#include "Stack.h"
#include<regex>
#include <iostream>
#include <string>
#include<regex>
using namespace std; 

const string ERROR_OF_EXPRESSION = "Вырвжение задано некорректно\n";


bool checkBalanceBrackets(const string& text, const size_t stackSize);
int getPrecedence(char op);
void getPostfixFromInfix(const string& infix, string& postfix, const size_t stackSize);