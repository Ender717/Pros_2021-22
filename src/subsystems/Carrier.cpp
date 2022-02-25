// Included libraries
#include "subsystems/Carrier.h"

// Constructor definitions ----------------------------------------------------
Carrier::Carrier(bool startDown) 
{
    isDown = startDown;
} 

// Public method definitions --------------------------------------------------
void Carrier::Initialize()
{
    CarrierConfig::leftCarrierPiston.set_value(isDown);
    CarrierConfig::rightCarrierPiston.set_value(isDown);
}

void Carrier::SetDown()
{
    CarrierConfig::leftCarrierPiston.set_value(true);
    CarrierConfig::rightCarrierPiston.set_value(true);
    isDown = true;
}

void Carrier::SetUp()
{
    CarrierConfig::leftCarrierPiston.set_value(false);
    CarrierConfig::rightCarrierPiston.set_value(false);
    isDown = false;
}

bool Carrier::IsDown() const
{
    return isDown;
}