#include <iostream>
#include "Collision2D.hpp"

template<typename Shape, typename Func>
void PrintResult(Func f, Shape const& A, Shape const& B)
{
  if(! f(A,B))
      std::cout << "No ";
  std::cout << "Collision Detected" << std::endl;
}

void TestCircle()
{
  std::cout << "TestCircle" << std::endl;
  //collision detected
  std::cout << "Overlap ";
  Circle circle1{5,5 ,20};
  Circle circle2{5,10,12};
  PrintResult(StaticCircleCollisionCheck,circle1,circle2);
  
  //circle just touching
  std::cout << "Just Touching ";
  circle1 = {5,10,5};
  circle2 = {5,20,5};
  PrintResult(StaticCircleCollisionCheck,circle1,circle2);
  
  //collision not detected
  std::cout << "Far apart ";
  circle1 = {5,50,20};
  circle2 = {5,10,12};
  PrintResult(StaticCircleCollisionCheck,circle1,circle2);
}

template<typename Func>
void TestRect( Func func, std::string const& str)
{
  std::cout << str << std::endl;
  //collision detected
  std::cout << "Overlap ";
  Rect rect1{ 4,6,5,1};
  Rect rect2{ 2,2,3,1};
  PrintResult(func, rect1, rect2);
  
  //collision not detected
  std::cout << "Far apart ";
  rect1 = { 4,6,5,1};
  rect2 = { 2,2,1,1};
  PrintResult(func, rect1, rect2);
}

int main()
{
  TestCircle();
  TestRect(AABB,"AABB");
  TestRect(AABBNonOpt,"AABBNonOpt");
  return 0;
}