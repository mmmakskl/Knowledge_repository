#include <algorithm>
#include <iterator>
#include <vector>
#include "io.h"

using namespace berezneva;

int main(void)  // (:key1 01001:key2 0xFFFA:key3 "Data":)
{
  std::vector<DataStruct> vec;
  std::copy_if(
    std::istream_iterator<DataStruct>(std::cin),
    std::istream_iterator<DataStruct>(),
    std::back_inserter(vec),
    [](const DataStruct& ds) { return ds.valid; }
  );
  std::sort(
    vec.begin(),
    vec.end(),
    [](const DataStruct& lhs, const DataStruct& rhs)
    {
      if (lhs.key1 < rhs.key1)
      {
        return true;
      }
      if (lhs.key2 < rhs.key2)
      {
        return true;
      }
      else
      {
        return lhs.key3 < rhs.key3;
      }
    }
  );
  std::cout << std::endl << std::endl;
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<DataStruct>(std::cout, "\n"));
 }
