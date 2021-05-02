#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

//the most basic thing in the world
struct Point
{
  Point(double _x, double _y);
  double x;
  double y;
};

//2 Points from vector 2d
struct Vector2D : private Point
{
  Vector2D(double _x1, double _y1, double _x2, double _y2);
  Vector2D(Point const& lhs, Point const& rhs);
  Vector2D(double _x, double _y);
  //expose to public without letting other people know that this is actually point
  Point::x;
  Point::y;
};

//described by p = p1 + tv
struct Line
{
  Line(Point const& p, Vector2D const& v);
  Point origin;
  Vector2D direction;
};

/**
* Check if the point is on the line
*/
bool PointOnLine(Line const&, Point const&);
double DistanceFromPointToLine(Line const& l, Point const& p);

#endif

