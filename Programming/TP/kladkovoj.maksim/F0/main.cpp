#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <functional>
#include <sstream>

#include "command.hpp"
#include "function.hpp"

using namespace kladkovoj;

int main()
{
  std::map<std::string, std::function<void(const std::vector<std::string>&)>> commandMap =
  {
    {"HELP", [](const std::vector<std::string>&)
    {
      command::help();
    }
    },
    {"CREATE", [](const std::vector<std::string>& tokens)
    {
      if(tokens.size() == 2)
      {
        command::create(tokens[1]);
      }
      else if(tokens.size() == 4)
      {
        int capacity = std::stoi(tokens[1]);
        int numItems = std::stoi(tokens[2]);
        command::create(capacity, numItems, tokens[3]);
      }
      else
      {
        std::cerr << "Invalid usage. Type HELP for a list of commands.\n";
      }
    }
    },
    {"SHOW", [](const std::vector<std::string>& tokens)
    {
      command::show(tokens);
    }
    },
    {"SOLVE_DP", [](const std::vector<std::string>& tokens)
    {
      if(tokens.size() == 2)
      {
        command::solveDP(tokens[1]);
      }
      else
      {
        throw std::invalid_argument("Requires a filename.");
      }
    }
    },
    {"SOLVE_BT", [](const std::vector<std::string>& tokens)
    {
      if(tokens.size() == 2)
      {
        command::solveBT(tokens[1]);
      }
      else
      {
        throw std::invalid_argument("Requires a filename.");
      }
    }
    },
    {"SOLVE_BB", [](const std::vector<std::string>& tokens)
    {
      if(tokens.size() == 2)
      {
        command::solveBB(tokens[1]);
      }
      else
      {
        throw std::invalid_argument("Requires a filename.");
      }
    }
    },
    {"SOLVE_BF", [](const std::vector<std::string>& tokens)
    {
      if(tokens.size() == 2)
      {
        command::solveBF(tokens[1]);
      }
      else
      {
        throw std::invalid_argument("Requires a filename.");
      }
    }
    }
  };

  std::string line;
  while(std::getline(std::cin, line))
  {
    std::istringstream iss(line);

    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
    if(tokens.empty())
    {
      continue;
    }

    try
    {
      auto it = commandMap.find(tokens[0]);
      if(it != commandMap.end())
      {
        it->second(tokens);
      }
      else if(!tokens[0].empty())
      {
        throw std::invalid_argument("<INVALID COMMAND>");
      }
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}
