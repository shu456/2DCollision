#include "GeoMath.hpp"

double DotProduct(Vector2D const& lhs, Vector2D const& rhs)
{
  return (lhs.x*rhs.x)+ (lhs.y*rhs.y);
}

double Length(Vector2D v)
{
  return sqrt( DotProduct(v,v) );
}

Vector2D operator+(Vector2D const& lhs, Vector2D const& rhs)
{
  Vector2D v(lhs);
  v += rhs;
  return v;
}

Vector2D& operator+=(Vector2D& lhs, Vector2D const& rhs)
{
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  return lhs;
}

Vector2D operator-(Vector2D const& lhs, Vector2D const& rhs)
{
  Vector2D v(lhs);
  v -= rhs;
  return v;
}

Vector2D& operator-=(Vector2D& lhs, Vector2D const& rhs)
{
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
  return lhs;
}

Vector2D operator*(Vector2D const& lhs, double const& scalar)
{
  Vector2D v(lhs);
  v *= scalar;
  return v;
}

Vector2D& operator*=(Vector2D& lhs, double const& scalar)
{
  lhs.x *= scalar;
  lhs.y *= scalar;
  return lhs;
}

bool operator==(Vector2D const& lhs, Vector2D const& rhs)
{
  return isEqual(lhs.x,rhs.x) && isEqual(lhs.y,rhs.y);
}

bool operator!=(Vector2D const& lhs, Vector2D const& rhs)
{
  return !(lhs==rhs);
}

Vector2D& normalized(Vector2D& lhs)
{
  double len = Length(lhs);
  lhs.x /= len;
  lhs.y /= len;
  return lhs;
}

Vector2D normalized(Vector2D const& lhs)
{
  Vector2D vRet(lhs);
  return normalized(vRet);
}