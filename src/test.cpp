#include "PID.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   float testValue = 0.0;
   PID pid(1.0, 1.0, 1.0, -200.0, 200.0, 2.0, 0.0);

   pid.SetTargetValue(2000.0);
   while (abs(100.0 - pid.PercentTarget()) > 0.01)
   {
      testValue += pid.GetControlValue(testValue);
      cout << testValue << endl;
      sleep(10);
   }

   return 0;
}
