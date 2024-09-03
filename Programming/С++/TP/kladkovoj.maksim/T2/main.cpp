#include <algorithm>
#include <iterator>
#include <vector>
#include "DataStruct.hpp"
#include "InputFormat.hpp"
#include <limits>

using namespace kladkovoj;

int main()
{
  std::vector<DataStruct> data;
  while (!std::cin.eof())
  {
    std::copy(std::istream_iterator<DataStruct>{std::cin}, std::istream_iterator<DataStruct>{}, std::back_inserter(data));
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  std::sort(data.begin(), data.end());
  std::copy(data.cbegin(), data.cend(), std::ostream_iterator<DataStruct>{std::cout, "\n"});
  return 0;
}
