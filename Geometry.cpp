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
  Vector2D const& v1 = l.direction;
  Vector2D v2(l.origin, p);

  // | v1 | * | v2 | * cos theta = scalar
  // let |v1| = 1 (Line construction will normalize the direction vector)
  // | v2 | * cos theta = scalar
  // with reference to C = A/H
  // cos theta = scalar / |v2| 
  double scalar = DotProduct(v1, v2);
  double len = Length(v2);

  return (scalar / len);
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
