#include "functions.h"

bool isLetter (const char &symbol)
{
    const string LETTERS = "abcde";
    return (LETTERS.find(symbol) != string::npos);
}

bool isDigit(const char &symbol)
{
    const string DIGITS = "0123456789";
    return (DIGITS.find(symbol) != string::npos);
}

bool  isID(const char &symbol)  {return isLetter(symbol);}

bool isUnsignedtInt(const string& str) 
{ return (str.length() == 1) ? isDigit(str[0]):  (isDigit(str[0]) && isUnsignedtInt(str.substr(1)));}

bool isMultiplier(const string& str) 
{ return  isUnsignedtInt(str) || isID(str[0]); }

bool isTerm(const string& str)  
{
    size_t pos = min(str.find('*'), str.find('/'));
    return  (pos == string::npos) ? isMultiplier(str):  isMultiplier(str.substr(0, pos)) && isTerm(str.substr(pos+1) );
}

bool isExpression(const string& str)
{
    size_t pos = min(str.find('+'), str.find('-'));
    return (pos == string::npos) ? isTerm(str): isTerm(str.substr(0, pos)) && isExpression(str.substr(pos + 1));
}