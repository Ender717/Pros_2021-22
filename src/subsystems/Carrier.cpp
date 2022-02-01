// Included libraries
#include "subsystems/Carrier.h"

// Constructor definitions ----------------------------------------------------
Carrier::Carrier() {} 

// Public method definitions --------------------------------------------------
void Carrier::SetDown()
{
    CarrierConfig::leftCarrierPiston.set_value(true);
    CarrierConfig::rightCarrierPiston.set_value(true);
}

void Carrier::SetUp()
{
    CarrierConfig::leftCarrierPiston.set_value(false);
    CarrierConfig::rightCarrierPiston.set_value(false);
}

void Carrier::Initialize()
{
    CarrierConfig::leftCarrierPiston.set_value(true);
    CarrierConfig::rightCarrierPiston.set_value(true);
}