#include "recursion_func.h"

bool isRealNumber(const std::string& str)
{
    std::size_t index = 0;
    if (std::size(str) == 0)
        return false;
    if (isSign(str[index]))
    {
        index++;
        if (isMantissa(str, index))
            return (isExponent(str, index) && size(str) == index);
    }
    return false;
}

bool isMantissa(const std::string& str, std::size_t& index)
{
    if (isUnsignedInt(str, index))
    {
        if (str[index] == '.')
        {
            index++;
            return isUnsignedInt(str, index);
        }
    }
    if (str[index] == '.')
    {
        index++;
        return isUnsignedInt(str, index);
    }
    return isUnsignedInt(str, index);
}

bool isExponent(const std::string& str, std::size_t& index)
{
    if (str[index] == 'E')
    {
        index++;
        if (isSign(str[index]))
        {
            index++;
            // if (index + 1 <= str.length())
            return isUnsignedInt(str, index);
        }
        return isUnsignedInt(str, index);
    }
    return false;

}

bool isUnsignedInt(const std::string& str, std::size_t& index)
{
    if (isDigit(str[index]))
    {
        index++;
        return isUnsignedInt(str, index);
    }
    return true;
}

bool isDigit(char c)
{
    return ('0' <= c && c <= '9');
}

bool isSign(char c)
{
    return (c == '+' || c == '-');
}
