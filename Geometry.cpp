#include "Geometry.hpp"
#include "GeoMath.hpp"

/**
* Check if the p and line origin has the same direction
*/
bool PointOnLine(Line const& l, Point const& p)
{
  Vector2D v2(l.origin, p);
  return l.direction == normalized(v2);
}

double DistanceFromPointToLine(Line const& l, Point const& p)
{
  Vector2D v2(l.origin, p);

  /**Not done yet.*/

  return DotProduct(v2, l.direction);
}

Line::Line(Point const& p, Vector2D const& v) : origin(p), direction(v) 
{ 
  normalized(direction); 
}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

Vector2D::Vector2D(double _x1, double _y1, double _x2, double _y2)
  : Point(_x1 - _x2, _y1 - _y2)
{}

Vector2D::Vector2D(Point const& lhs, Point const& rhs) : Point(rhs.x - lhs.x, rhs.y - lhs.y) {}

Vector2D::Vector2D(double _x, double _y) : Point(_x, _y) {}
