#pragma once
#include<string>
#include<iostream>
using namespace std;
bool isLetter(const char &symbol);
bool isDigit(const char &symbol);
bool  isID(const char &symbol);
bool isUnsigntInt(const string &str);
bool isMultiplier(const string& str);
bool isTerm(const string& str);
bool isExpression(const string& str);