#include <iostream>
#include <math.h>
#include <omp.h>
#include <vector>
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

double Particle::toRads(double angleHex){
    return angleHex*M_PI/180;
}

map<double, pair<double, double>> Particle::getTrajectory(){
    return trajectory;
}

double Particle::getTime(){
    if(initialPositionY == 0){
        return -2*(initialVelocity * sin(angle))/-9.8;
    }else{
        double t1 = -2*(initialVelocity * sin(angle))/-9.8;
        double finalVelocity = sqrt(initialVelocity*initialVelocity + 2*-9.8*(-initialPositionY));
        return t1 + (finalVelocity-initialVelocity)/9.8;
    }
}

map<double, pair<double, double>> Particle::defaultTrajectory(int frames){
    double timeStep = getTime()/frames;
    map<double, pair<double, double>> newTrajectory;
    for (int i = 0; i <=frames; ++i) {
        newTrajectory[i*timeStep] = {0,0};
    }

    return newTrajectory;
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

void Particle::calculateTrajectory(int numThreads) {
    double v0x = initialVelocity * cos(angle);
    double v0y = initialVelocity * sin(angle);


    vector<double> times;
    vector<pair<double, double>> positions;

    for (const auto& entry : trajectory) {
        times.push_back(entry.first);
        positions.push_back({0, 0});
    }

   
    #pragma omp parallel for num_threads(numThreads)
    for (size_t i = 0; i < times.size(); ++i) {
        double t = times[i];
        double x = v0x * t;
        double y = initialPositionY + v0y * t - 0.5 * 9.8 * t * t;
        positions[i] = make_pair(x, y);
    }

    
    size_t index = 0;
    for (auto& entry : trajectory) {
        entry.second = positions[index];
        ++index;
    }
}
