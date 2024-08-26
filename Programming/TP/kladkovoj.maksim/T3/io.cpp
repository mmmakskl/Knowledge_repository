#include "shape.hpp"

std::istream& kladkovoj::operator>>(std::istream& input, Sep&& res)
{
  std::istream::sentry sentry(input);

  if(!sentry)
    return input;

  char ch;

  input >> ch;
  if(!input || ch != res.exp)
    input.setstate(std::ios::failbit);

  return input;
}


std::istream& kladkovoj::operator>>(std::istream& input, Point& res)
{
  std::istream::sentry sentry(input);

  if(!sentry)
    return input;

  input >> Sep('(') >> res.x >> Sep(';') >> res.y >> Sep(')');

  return input;
}

std::istream& kladkovoj::operator>>(std::istream& input, Polygon& res)
{
  std::istream::sentry sentry(input);

  if(!sentry)
    return input;

  size_t size;

  input >> size;

  if(size < 3)
  {
    input.setstate(std::istream::failbit);
    return input;
  }

  res.points.clear();
  res.points.resize(size);

  for(Point& point : res.points)
    input >> point;

  return input;
}

std::ostream& kladkovoj::operator<<(std::ostream& out,const Point& pnt)
{
  std::ostream::sentry sentry(out);

  if(!sentry)
    return out;

  out << '(' << pnt.x << ';' << pnt.y << ')';
  return out;
}


std::ostream& kladkovoj::operator<<(std::ostream& out,const Polygon& poly)
{
  std::ostream::sentry sentry(out);

  if(!sentry)
    return out;

  out << poly.points.size() << ' ';

  for (const Point& point : poly.points)
    out << point << ' ';
  return out;
}
