#ifndef RECURSION_FUNC
#define RECURSION_FUNC
#include <iostream>
#include <string>

bool isRealNumber(const std::string& str);

bool isMantissa(const std::string& str, std::size_t& index);

bool isExponent(const std::string& str, std::size_t& index);

bool isUnsignedInt(const std::string& str, std::size_t& index);

bool isSign(char c);

bool isDigit(char c);

const std::string IN_FILE = "inTest.txt";

const std::string OUT_FILE = "outTest.txt";

#endif
