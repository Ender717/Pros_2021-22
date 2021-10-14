#pragma once
#ifndef mathTools_h
#define mathTools_h

#include "corecrt_math_defines.h"

namespace mathTools
{

float getwheelDistanceMoved(float ticksMoved, float wheelDiameter, float ticksPerRotation);

float getHypotenuse(float x, float y);

int sgn(float a);

float getDegrees(float x);

float getRadians(float x);

float round360(float given);

int direction360(float first, float second);

float distance360(float first, float second);

float radiansToGyro(float r);

} // namespace mathTools

#endif