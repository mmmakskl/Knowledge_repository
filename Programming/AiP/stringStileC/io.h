#ifndef _IO_H
#define _IO_H

#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <iomanip>

namespace berezneva
{
  bool isULL_OCT(const std::string& str);
  bool isULL_HEX(const std::string& str);
  bool isString(const std::string& str);

  struct DataStruct
  {
    unsigned long long key1;  // ULL OCT 01001; 076
    unsigned long long key2;  // ULL HEX 0xFFFA; 0X0100f
    std::string key3;
    bool valid;
  };

  std::istream& operator>>(std::istream& in, DataStruct& ds);
  std::ostream& operator<<(std::ostream& out, const DataStruct& ds);

  std::pair<std::string, std::string> getNextPair(std::string& s);

  class iofmtguard
  {
  public:
    iofmtguard(std::basic_ios< char >& s);
    ~iofmtguard();
  private:
    std::basic_ios< char >& s_;
    char fill_;
    std::streamsize precision_;
    std::basic_ios< char >::fmtflags fmt_;
  };
}
#endif
