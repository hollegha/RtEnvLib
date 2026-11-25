
#pragma once
#include "OdoParam.h"

const float TICKS_2_CM = 100.0 / (float)TICKS_PER_METER;

class Odom {
public:
  Odom()
  {
    reset();
  }
  void reset();
  void odomCB(Encoder2* src);
  void calcOdom();

  float getX()
  { 
    return xPos * TICKS_2_CM;
  }
  float getY()
  {
    return yPos * TICKS_2_CM;
  }
  float phiGrad()
  {
    return (180.0 / M_PI)* phi;
  }
public:
  int incVectLen;
  int angleTicks;
  float phi; // in rad
  float xPos, yPos; // in Ticks
};

extern Odom odom;

