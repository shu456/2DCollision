#ifndef COLLISION2D_HPP
#define COLLISION2D_HPP

#include <cmath>
#include <limits>

#include "shape.hpp"

//helpers
template<typename T>
bool isEqual(T a, T b)
{
    return std::fabs(a - b) < std::numeric_limits<T>::epsilon();
}

template<typename T>
bool isEqual(T a)
{
    return std::fabs(a) < std::numeric_limits<T>::epsilon();
}

//Check with p1 is within p2 and p3
bool NumberWithinRanged(double p1, double p2, double p3)
{
  return (p1 > p2) && (p1 < p3);
}

/* Single Axis. Non-simplified for explanation
*/
bool AxisAlignedNonOpt(double p1, double w1, double p2, double w2)
{
  double p1Start = p1 - w1;
  double p1End   = p1 + w1;
  //check if p2 is within p1 - width and p1 + width
  if ( NumberWithinRanged(p2-w2, p1Start,p1End) )
    return true;
  //check if p2 + width is within p1 - width and p1 + width
  if ( NumberWithinRanged(p2+w2, p1Start,p1End) )
    return true;
  
  return false;
}

//2D Axis Aligned Bounding box non optimized
bool AABBNonOpt(Rect const& A, Rect const& B)
{
  //check x axis and check y axis
  return( AxisAlignedNonOpt(A.center.x,A.width/2.0,B.center.x,B.width/2.0) &&
          AxisAlignedNonOpt(A.center.y,A.height/2.0,B.center.y,B.height/2.0) );
}

/* Single Axis simplified
*  case 1 - true
*  p1------>p1+width1
*    p2---------->p2+width2
*  case 2 - false
*  p1------>p1+width1
*              p2---------->p2+width2
*  case 3 - true
*     p1------>p1+width1
*  p2---------->p2+width2
*  case 4 - false
*                 p1------>p1+width1
*  p2---------->p2+width2
*/
bool AxisAligned(double p1, double w1, double p2, double w2)
{
  return ( (p1 + w1) > p2 && (p2 + w2) > p1 );
}

//2D Axis Aligned Bounding box
bool AABB(Rect const& A, Rect const& B)
{
  double halfAWidth = A.width / 2.0;
  double halfBWidth = B.width / 2.0;
  double halfAHeight = A.height / 2.0;
  double halfBHeight = B.height / 2.0;
  return AxisAligned(A.center.x - halfAWidth ,A.width ,B.center.x - halfBWidth ,B.width) &&
         AxisAligned(A.center.y - halfAHeight,A.height,B.center.y - halfBHeight,B.height);
}

//Circle
bool StaticCircleCollisionCheck(Circle const& A, Circle const& B)
{
  double dx = B.center.x - A.center.x;
  double dy = A.center.y - B.center.y;
  double dist  = dx*dx + dy*dy;
  double radii = A.radius + B.radius;
  //if the distance is lesser then sum of both radius squared
  dist = (radii*radii) - dist;
  
  if( dist > 0 )
    return true;
  
  //if just touching the border
  if( isEqual(dist) )
    return true;
  
  return false;
}

#endif
