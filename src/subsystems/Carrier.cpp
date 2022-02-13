// Included libraries
#include "subsystems/Carrier.h"

// Constructor definitions ----------------------------------------------------
Carrier::Carrier(bool startDown) 
{
    CarrierConfig::leftCarrierPiston.set_value(startDown);
    CarrierConfig::rightCarrierPiston.set_value(startDown);
    isDown = startDown;
    hasGoal = false;
} 

// Public method definitions --------------------------------------------------
void Carrier::SetDown()
{
    if(!isDown)
    {
        CarrierConfig::leftCarrierPiston.set_value(true);
        CarrierConfig::rightCarrierPiston.set_value(true);
        isDown = true;
    }
}

void Carrier::SetUp()
{
    if(isDown)
    {
        CarrierConfig::leftCarrierPiston.set_value(false);
        CarrierConfig::rightCarrierPiston.set_value(false);
        isDown = false;
    }
}

bool Carrier::IsDown()
{
    return isDown;
}

bool Carrier::HasGoal()
{
    return hasGoal;
}