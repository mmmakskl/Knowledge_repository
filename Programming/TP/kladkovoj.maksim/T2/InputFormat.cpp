#include "InputFormat.hpp"
#include <iomanip>
#include <bitset>
#include <cmath>

namespace kladkovoj
{
  std::istream& operator>>(std::istream& in, DelimiterIO&& dest)
  {
    std::istream::sentry sentry(in);
    if(!sentry)
    {
      return in;
    }
    char c = '\0';
    in >> c;
    if (in && (c != dest.del))
    {
      in.setstate(std::ios::failbit);
    }
    return in;
  }

  std::istream& operator>>(std::istream& in, DoubleIO&& dest)
  {
    std::istream::sentry sentry(in);
    if(!sentry)
    {
      return in;
    }
    int mantissa = 0;
    int number = 0;
    int power = 0;
    in >> mantissa >> DelimiterIO{'.'} >> number;
    if (in.peek() == 'e')
    {
      in >> DelimiterIO{ 'e' };
    }
    else
    {
      in >> DelimiterIO{ 'E' };
    }
    in >> power;
    dest.db = (mantissa * 1.0 + number * 0.01) * std::pow(10, power);
    return in;
  }

  std::istream& operator>>(std::istream& in, LongLongBinIO&& dest)
  {
    std::istream::sentry sentry(in);
    if(!sentry)
    {
      return in;
    }
    unsigned long long number = 0;
    char c = '\0';
    while (in >> c)
    {
      if (c == '0' || c == '1')
      {
        number = (number << 1) + (c - '0');
      }
      else
      {
        break;
      }
    }
    dest.ll = number;
    return in;
  }

  std::istream& operator>>(std::istream& in, StringIO&& dest)
  {
    std::istream::sentry sentry(in);
    if(!sentry)
    {
      return in;
    }
    return std::getline(in >> DelimiterIO{'"'}, dest.str, '"');
  }

  std::istream& operator>>(std::istream& in, LabelIO&& dest)
  {
    std::istream::sentry sentry(in);
    if(!sentry)
    {
      return in;
    }
    in >> DelimiterIO{'"'};
    in >> dest.lab >> DelimiterIO{'"'};
    return in;
  }
}
