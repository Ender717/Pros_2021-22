#include "processes/Position.hpp"

// Constructor Definitions ----------------------------------------------------
Position::PositionBuilder::PositionBuilder()
{
    leftTrackingDistance = DEFAULT_LEFT;
    rightTrackingDistance = DEFAULT_RIGHT;
    strafeTrackingDistance = DEFAULT_STRAFE;
    startX = 0.0;
    startY = 0.0;
    startTheta = 0.0;
}

// Public Method Definitions --------------------------------------------------
Position::PositionBuilder Position::PositionBuilder::WithLeftDistance(double leftTrackingDistance)
{
    this->leftTrackingDistance = leftTrackingDistance;
    return *this;
}

Position::PositionBuilder Position::PositionBuilder::WithRightDistance(double rightTrackingDistance)
{
    this->rightTrackingDistance = rightTrackingDistance;
    return *this;
}

Position::PositionBuilder Position::PositionBuilder::WithStrafeDistance(double strafeTrackingDistance)
{
    this->strafeTrackingDistance = strafeTrackingDistance;
    return *this;
}

Position::PositionBuilder Position::PositionBuilder::WithStartX(double startX)
{
    this->startX = startX;
    return *this;
}

Position::PositionBuilder Position::PositionBuilder::WithStartY(double startY)
{
    this->startY = startY;
    return *this;
}

Position::PositionBuilder Position::PositionBuilder::WithStartAngle(double startAngle)
{
    this->startTheta = (startAngle * 3.1415 / 180.0);
    return *this;
}

Position Position::PositionBuilder::Build()
{
    return Position(*this);
}

// Constructor Definitions ----------------------------------------------------
Position::Position()
{
    leftTrackingDistance = 0.0;
    rightTrackingDistance = 0.0;
    strafeTrackingDistance = 0.0;
    currentX = 0.0;
    currentY = 0.0;
    currentTheta = 0.0;
    lastLeft = 0.0;
    lastRight = 0.0;
    lastStrafe = 0.0;
    lastTheta = 0.0;
    resetX = 0.0;
    resetY = 0.0;
    resetTheta = 0.0;
}

Position::Position(PositionBuilder builder)
{
    // Get builder data
    this->leftTrackingDistance = builder.leftTrackingDistance;
    this->rightTrackingDistance = builder.rightTrackingDistance;
    this->strafeTrackingDistance = builder.strafeTrackingDistance;
    this->currentX = builder.startX;
    this->currentY = builder.startY;
    this->currentTheta = builder.startTheta;

    // Initialize other data
    lastLeft = 0.0;
    lastRight = 0.0;
    lastStrafe = 0.0;
    lastTheta = currentTheta;
    resetX = currentX;
    resetY = currentY;
    resetTheta = currentTheta;
}

// Private Method Definitions -------------------------------------------------
void Position::SetResetPosition()
{
    lastLeft = 0.0;
    lastRight = 0.0;
    lastStrafe = 0.0;
    lastTheta = currentTheta;
    resetX = currentX;
    resetY = currentY;
    resetTheta = currentTheta;
}

// Public Method Definitions --------------------------------------------------
void Position::UpdatePosition(double leftValue, double rightValue, double strafeValue)
{
    // Calculate the distance moved by each wheel since the last cycle
    double leftDistance = leftValue - lastLeft;
    double rightDistance = rightValue - lastRight;
    double strafeDistance = strafeValue - lastStrafe;

    // Calculate absolute theta
    double totalLeft = leftValue;
    double totalRight = rightValue;
    currentTheta = ((totalRight - totalLeft) / (leftTrackingDistance + rightTrackingDistance)) + resetTheta;

    // Calculate the change in theta
    double thetaChange = currentTheta - lastTheta;

    // Cap current theta
    if (currentTheta > 3.1415)
        currentTheta -= 7.2830;
    else if (currentTheta < -3.1415)
        currentTheta += 7.2830;

    // Calculate the local offset
    double forwardDistance = 0.0;
    double sidewaysDistance = 0.0;
    if (thetaChange == 0.0)
    {
        sidewaysDistance = strafeDistance;
        forwardDistance = rightDistance;
    }
    else
    {
        sidewaysDistance = (2.0 * sin(thetaChange / 2.0)) * ((strafeDistance / thetaChange) + strafeTrackingDistance);
        forwardDistance = (2.0 * sin(thetaChange / 2.0)) * ((leftDistance / thetaChange) + leftTrackingDistance);
    }

    // Calculate the average orientation
    double averageTheta = lastTheta + (thetaChange / 2.0);

    // Calculate the global offset
    double xChange = sidewaysDistance * -sin(averageTheta) + forwardDistance * cos(averageTheta);
    double yChange = sidewaysDistance * cos(averageTheta) + forwardDistance * sin(averageTheta);

    // Calculate the new absolute position
    currentX += xChange;
    currentY += yChange;

    // Update the stored previous values
    lastLeft = leftValue;
    lastRight = rightValue;
    lastStrafe = strafeValue;
    lastTheta = currentTheta;
}

void Position::SetX(double x)
{
    currentX = x;
    SetResetPosition();
}

void Position::SetY(double y)
{
    currentY = y;
    SetResetPosition();
}

void Position::SetAngle(double angle)
{
    currentTheta = (angle * 3.1415 / 180.0);
    SetResetPosition();
}

void Position::SetPosition(double x, double y, double theta)
{
    currentX = x;
    currentY = y;
    currentTheta = theta;
    SetResetPosition();
}

double Position::GetX() const
{
    return currentX;
}

double Position::GetY() const
{
    return currentY;
}

double Position::GetTheta() const
{
    return currentTheta;
}

double Position::GetAngle() const
{
    return (currentTheta * 180.0 / 3.1415);
}