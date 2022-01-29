// Included libraries
#include "subsystems/Carrier.h"

// Constructor definitions ----------------------------------------------------
Carrier::Carrier() {} 

// Public method definitions --------------------------------------------------
void Carrier::SetCarrier(float power)
{
    CarrierConfig::leftCarrierMotor.move(power);
    CarrierConfig::rightCarrierMotor.move(power);
}

void Carrier::SetDown()
{
    PID carrierPID(3.5, 0.95, 0.1, 0.0, -125.0, 125.0, 85.0, 0.0);
    carrierPID.SetTargetValue(CarrierConfig::DOWN_POSITION);
    float current = CarrierConfig::leftCarrierMotor.get_position();
    float controlValue = carrierPID.GetControlValue(current);

    while(fabs(CarrierConfig::DOWN_POSITION - current) > 1 || controlValue > 1)
    {
        current = CarrierConfig::leftCarrierMotor.get_position();
        controlValue = carrierPID.GetControlValue(current);
        SetCarrier(controlValue);
        pros::delay(2);
    }
}

void Carrier::SetUp()
{
    PID carrierPID(3.5, 0.95, 0.1, 0.0, -125.0, 125.0, 85.0, 0.0);
    carrierPID.SetTargetValue(CarrierConfig::UP_POSITION);
    float current = CarrierConfig::leftCarrierMotor.get_position();
    float controlValue = carrierPID.GetControlValue(current);

    while(fabs(CarrierConfig::UP_POSITION - current) > 1 || controlValue > 1)
    {
        current = CarrierConfig::leftCarrierMotor.get_position();
        controlValue = carrierPID.GetControlValue(current);
        SetCarrier(controlValue);
        pros::delay(2);
    }
}

void Carrier::Initialize()
{
    CarrierConfig::leftCarrierMotor.tare_position();
    CarrierConfig::rightCarrierMotor.tare_position();
}