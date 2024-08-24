# pragma once
#include <iostream>
using namespace std;

class Particle {
private:
    double initialVelocity;
    double angle;
    double initialPositionY;

public:
    Particle(double initialVelocity, double angle, double initialPositionY);
    
    double getInitialVelocity();
    double getAngle();
    double getInitialPositionY();

    void setInitialVelocity(double initialVelocity);
    void setAngle(double angle);
    void setInitialPositionY(double initialPositionY);
};
