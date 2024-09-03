#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <vector>  // vector
#include <string>  // string

namespace command
{
  void help();
  void create(int capacity, int numItems, const std::string& filename);
  void create(const std::string& filename);
  void show(const std::vector<std::string>& tokens);
  void solveDP(const std::string& filename);
  void solveBT(const std::string& filename);
  void solveBB(const std::string& filename);
  void solveBF(const std::string& filename);
}

#endif
