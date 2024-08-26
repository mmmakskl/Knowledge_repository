#ifndef INPUT_FORMAT_HPP
#define INPUT_FORMAT_HPP

#include <string>
#include <iostream>

namespace kladkovoj
{
  struct DelimiterIO
  {
    char del;
  };

  struct DoubleIO
  {
    double& db;
  };

  struct LongLongBinIO
  {
    unsigned long long& ll;
  };

  struct StringIO
  {
    std::string& str;
  };

  struct LabelIO
  {
    std::string lab;
  };

  std::istream& operator>>(std::istream& in, DelimiterIO&& dest);
  std::istream& operator>>(std::istream& in, DoubleIO&& dest);
  std::istream& operator>>(std::istream& in, LongLongBinIO&& dest);
  std::istream& operator>>(std::istream& in, StringIO&& dest);
  std::istream& operator>>(std::istream& in, LabelIO&& dest);
}

#endif
