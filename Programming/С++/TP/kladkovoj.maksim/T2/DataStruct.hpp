#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iostream>

// DBL SCI | ULL BIN
namespace kladkovoj
{
  struct DataStruct
  {
    double key1;
    unsigned long long key2;
    std::string key3;
  };

  bool operator<(const DataStruct& rhs, const DataStruct& lhs);
  std::istream& operator>>(std::istream& in, DataStruct& dest);
  std::ostream& operator<<(std::ostream& out, const DataStruct& dest);
  std::string fromDoubleToScientific(double val);
  std::string fromULLtoBinary(unsigned long long val);
}

#endif
