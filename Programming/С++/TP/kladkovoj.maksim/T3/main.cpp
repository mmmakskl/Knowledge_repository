#include <iterator>
#include <iomanip>
#include <fstream>
#include <limits>
#include <map>
#include <functional>

#include "command.hpp"

using namespace kladkovoj;

int main(int argC, char *argV[])
{
  if (argC != 2)
  {
    std::cerr << "INCORRECT USAGE" << std::endl;
    return 1;
  }

  std::string fileName = argV[1];

  std::ifstream file(fileName);

  if (!file)
  {
    std::cerr << "File not found!" << std::endl;
    return 1;
  }

  std::cout << std::setprecision(1) << std::fixed;
  std::vector<Polygon> data;
  while (!file.eof())
  {
    std::copy(std::istream_iterator<Polygon>(file), std::istream_iterator<Polygon>(), std::back_inserter(data));
    if (!file.eof()&& file.fail())
    {
      file.clear();
      file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  std::map<std::string, std::function<void(const std::vector<Polygon>&)>> commandMap =
  {
    {"AREA", command::area},
    {"MIN", command::min},
    {"MAX", command::max},
    {"COUNT", command::count},
    {"RECTS", command::rects},
    {"INTERSECTIONS", command::intersections}
  };

  while (!std::cin.eof())
  {
    std::string cmd;

    std::cin >> cmd;

    try
    {
      auto it = commandMap.find(cmd);
      if (it != commandMap.end())
        it->second(data);
      else if (!cmd.empty())
        throw std::invalid_argument("<INVALID COMMAND>");
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}
