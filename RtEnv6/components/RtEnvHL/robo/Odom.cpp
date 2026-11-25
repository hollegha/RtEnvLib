
#include "Encoder2.h"
#include "Odom.h"

Odom odom;

extern Encoder2 encR, encL;


inline int abs17(int val)
{
  if (val < 0)
    return -val;
  return val;
}

void Odom::reset()
{
  incVectLen = angleTicks = 0;
  xPos = yPos = 0; phi = 0;
}

void Odom::odomCB(Encoder2* src) // ISR
{
  // for vectorLen src is irrelevant
  incVectLen += src->getDir();

  if (src == &encL)
    angleTicks -= encL.getDir();
  else if (src == &encR)
    angleTicks += encR.getDir();

  if (angleTicks > 0)
    angleTicks = angleTicks % TICKS_PER_TURN;
  else if( angleTicks<0 )
    angleTicks = angleTicks % -TICKS_PER_TURN;
}


void Odom::calcOdom() // Task level
{
  phi = ((float)angleTicks * 2.0 * M_PI) / (float)TICKS_PER_TURN;
  
  if (phi > 0 && phi > M_PI)
    phi = -(2.0 * M_PI - phi);
  else if (phi < -M_PI)
    phi = 2.0 * M_PI + phi;

  if (abs17(incVectLen) < MEAS_INC) // ~1cm
    return;
  float vectLen = incVectLen; incVectLen = 0;
  vectLen *= 0.5;
  xPos = xPos + cos(phi) * vectLen;
  yPos = yPos + sin(phi) * vectLen;
}