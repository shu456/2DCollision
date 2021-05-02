#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Geometry.hpp"

struct BaseShape
{
  BaseShape(double _x,double _y) : center(_x,_y) {}
  Point center;
};

struct Rect : public BaseShape
{
  template<typename ... Args>
  Rect(double _w, double _h , Args && ... args) :
    width(_w),height(_h),BaseShape(args...){}
  double width;
  double height;
};

struct Circle : public BaseShape
{
  template<typename ... Args>
  Circle(double _r, Args && ... args) :
    radius(_r),BaseShape(args...){}
  double radius;
};

#endif
