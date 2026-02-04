
#pragma once

#include "ControlBasics.h"


class RpmController {
public:
  RateLim rl;
public:
  RpmController(PIDParam* aPara) : rl(100)
  {
    rl.F_SAMPLE = 300.0; rl.SetRateSec(100);
    on = false;
    out = sum = 0;
    par = aPara;
  }

  void setDemand(int aVal)
  {
    rl.in = aVal;
  }
  float getActDemand()
  {
    return rl.out;
  }
  void setRate(float aRate)
  {
    rl.SetRateSec(aRate);
  }

  void calcOneStep(float aSensVal)
  {
    const float F_DIFF = 100.0;
    const float DT = 1.0 / 300.0;

    rl.CalcOneStep();
    float abw = rl.out - aSensVal;

    diff = abw - z3;
    z3 = z2; z2 = z1; z1 = abw;
    diff = diff * F_DIFF;

    if (KI != 0)
      sum += abw;

    out = par->KP * abw + par->KD * diff + sum * par->KI * DT;
  }
private:
  float x_n1;
  float sum;
  float z1, z2, z3;
public:
  float out;
  float diff;
  bool on;
  PIDParam* par;
};


PIDParam rpmPara(0.1, 0.0, 0.0, 0.0, "rpm");

RpmController rpmCL(&rpmPara), rpmCR(&rpmPara);






