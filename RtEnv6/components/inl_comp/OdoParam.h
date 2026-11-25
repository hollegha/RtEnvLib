#pragma once

const float RPM_KP = 2.0E-3;
const float RPM_KD = 1.0E-4;
const float RPM_KI = 2.0E-2;

// acceleration of RPM controller
const float RPM_RATE = 1000.0;

const int TICKS_PER_TURN = 1540; // gemessen
const int TICKS_PER_METER = 1616; // gerechnet

// len of odo-vector increments in ticks
const int MEAS_INC = 28;



