//
//    FILE: AverageAngle.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: class for averaging angles
//     URL: https://github.com/RobTillaart/Arduino
//
// HISTORY:
//
// 0.1.0 2017-11-21 initial version
// 0.1.1 2017-12-09 fixed negative values of average
//

#include "AverageAngle.h"


/////////////////////////////////////////////////////
//
// PUBLIC
//
AverageAngle::AverageAngle(const enum AngleType type)
{
  _type = type;
  reset();
}

void AverageAngle::add(float alpha, float length)
{
  if (_type == AverageAngle::DEGREES )
  {
    alpha *= (PI / 180.0);
  }
  _sumx += cos(alpha) * length;
  _sumy += sin(alpha) * length;
  _count++;
}

void AverageAngle::reset()
{
  _sumx = 0;
  _sumy = 0;
  _count = 0;
}

float AverageAngle::getAverage()
{
  float angle = atan2(_sumy, _sumx);
  if (angle < 0) angle += (PI*2);
  if (_type == AverageAngle::DEGREES )
  {
    angle *= (180.0 / PI);
  }
  return angle;
}


// END OF FILE