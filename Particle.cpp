#include <iostream>
#include <math.h>
#include "Particle.hpp"

Particle::Particle(double initialVelocity, double angle, double initialPositionY){
    this->initialVelocity = initialVelocity;
    this->angle = angle;
    this->initialPositionY = initialPositionY;
}

double Particle::getInitialVelocity() {
    return initialVelocity;
}

double Particle::getAngle() {
    return angle;
}

double Particle::getInitialPositionY(){
    return initialPositionY;
}

map<double, pair<double, double>> Particle::getTrajectory(){
    return trajectory;
}

double Particle::getTime(){
    if(initialPositionY == 0){
        return -2*(initialVelocity * sin(angle))/9.8;
    }else{
        double t1 = -2*(initialVelocity * sin(angle))/9.8;
        double finalVelocity = sqrt(initialVelocity*initialVelocity + 2*9.8*initialPositionY);
        return t1 + (finalVelocity-initialVelocity)/9.8;
    }
}

void Particle::setInitialVelocity(double initialVelocity){
    this->initialVelocity = initialVelocity;
}

void Particle::setAngle(double angle){
    this->angle = angle;
}

void Particle::setInitialPositionY(double initialPositionY){
    this->initialPositionY = initialPositionY;
}

void Particle::setTrajectory(map<double, pair<double, double>> trajectory){
    this->trajectory = trajectory;
}