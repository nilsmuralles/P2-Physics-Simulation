#include <iostream>
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

void Particle::setInitialVelocity(double initialVelocity){
    this->initialVelocity = initialVelocity;
}

void Particle::setAngle(double angle){
    this->angle = angle;
}

void Particle::setInitialPositionY(double initialPositionY){
    this->initialPositionY = initialPositionY;
}