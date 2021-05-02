#include <iostream>
#include "../Geometry.hpp"

template<typename Func>
void PrintResult(Func f, Line const& A, Point const& B)
{
  if (!f(A, B))
    std::cout << "No ";
  std::cout << "Point on line" << std::endl;
}

void PointOnLineTest()
{
  std::cout << "PointOnLineTest - Positive" << std::endl;
  Vector2D v1(2,2);
  Point p1(0, 0);
  Line line(p1, v1);

  Point p2(5,5);
  PrintResult(PointOnLine, line, p2);
}