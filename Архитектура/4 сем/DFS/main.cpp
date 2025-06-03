#include "DFS.hpp"

int main()
{
  std::vector< std::string > matrix =
  {
    "01100100",
    "10010000",
    "10001100",
    "01001000",
    "00110000",
    "10100011",
    "00000100",
    "00000100",
  };

  try
  {
    DFS(matrix, std::cout);
  }
  catch (const std::exception& e)
  {
    std::cout << "Error message\n";
    return 1;
  }
  return 0;
}