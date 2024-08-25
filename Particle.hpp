# pragma once
#include <iostream>
#include <map>
#include <utility>
using namespace std;

class Particle {
private:
    double initialVelocity;
    double angle;
    double initialPositionY;
    double time;
    map<double, pair<double, double>> trajectory;

public:
    Particle(double initialVelocity, double angle, double initialPositionY);
    
    double getInitialVelocity();
    double getAngle();
    double getInitialPositionY();
    double getTime();
    map<double, pair<double, double>> getTrajectory();

    void setInitialVelocity(double initialVelocity);
    void setAngle(double angle);
    void setInitialPositionY(double initialPositionY);
    void setTrajectory(map<double, pair<double, double>> trajectory);
};
