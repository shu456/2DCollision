#ifndef GeoMath_HPP
#define GeoMath_HPP

#include <cmath>
#include <limits>

#include "Geometry.hpp"

/**
* File contain the basic math required for geometry
*/

//For comparable of double and float
template<typename T>
bool isEqual(T a, T b)
{
  return std::fabs(a - b) < std::numeric_limits<T>::epsilon();
}

template<typename T>
bool isEqualZero(T a)
{
  return std::fabs(a) < std::numeric_limits<T>::epsilon();
}


/*Able to find the squared length of a vector when lhs == rhs
* consist of the angle value. Do note that cos 0 = 1, cos (pi/2) = 0
* | a | * | b | * cos theta = ax * bx + ay * by
*/
double DotProduct(Vector2D const& lhs, Vector2D const& rhs);

/*
* | a | = sqrt ( ax*ax + ay*ay )
*/
double Length(Vector2D v);

/*
* Adding 2 vector2d
*/
Vector2D operator+(Vector2D const& lhs, Vector2D const& rhs);
Vector2D& operator+=(Vector2D& lhs, Vector2D const& rhs);
Vector2D operator-(Vector2D const& lhs, Vector2D const& rhs);
Vector2D& operator-=(Vector2D & lhs, Vector2D const& rhs);

Vector2D operator*(Vector2D const& lhs, double const& scalar);
Vector2D& operator*=(Vector2D& lhs, double const& scalar);

Vector2D& normalized(Vector2D& lhs);
Vector2D normalized(Vector2D const& lhs);

bool operator==(Vector2D const& lhs, Vector2D const& rhs);
bool operator!=(Vector2D const& lhs, Vector2D const& rhs);
#endif
