#include "DFS.hpp"
#include <stack>
#include <vector>
#include <iostream>
#include <stdexcept>

void DFS(const std::vector<std::string>& matrix, std::ostream& out)
{
  if (matrix.empty())
  {
    throw std::logic_error("ERROR!! Empty graph.");
  }

  std::stack<size_t> stack;
  std::vector<size_t> nodes(matrix.size(), 0);
  std::vector<size_t> result;
  size_t num = matrix.size();

  stack.push(0);
  nodes[0] = 1;

  while (!stack.empty())
  {
    size_t current = stack.top();
    stack.pop();

    if (nodes[current] == 1)
    {
      result.push_back(current);
      nodes[current] = 2;
    }

    std::string str = matrix[current];
    for (int i = str.size() - 1; i >= 0; --i)
    {
      if (str[i] == '1' && nodes[i] == 0)
      {
        stack.push(i);
        nodes[i] = 1;
      }
    }
  }

  if (result.empty())
  {
    throw std::logic_error("ERROR!! No nodes visited.");
  }

  for (size_t i = 0; i < result.size(); i++)
  {
    out << result[i] << (i == result.size() - 1 ? "\n" : " -> ");
  }
}