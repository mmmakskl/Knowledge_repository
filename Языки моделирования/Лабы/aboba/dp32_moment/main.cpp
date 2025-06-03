#include <iostream>
class A
{
public:
  void hello() {
    std::cout << "A\n";
  };
};

class B
{
public:
  void hello() {
    std::cout << "B\n";
  };
};

class C : public A, public B
{
public:
  void hello() {};
};

int main()
{
  C c;
  c.hello();
  return 0;
}
