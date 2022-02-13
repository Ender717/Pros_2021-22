// Included libraries
#include "subsystems/Carrier.h"

// Constructor definitions ----------------------------------------------------
Carrier::Carrier(int n) 
{
    isDown = false;
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

void Carrier::Initialize()
{
    CarrierConfig::leftCarrierPiston.set_value(false);
    CarrierConfig::rightCarrierPiston.set_value(false);
}