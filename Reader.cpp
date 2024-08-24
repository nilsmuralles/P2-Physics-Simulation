#include <iostream>
#include <fstream>
#include <Vector>
#include "Particle.hpp"
using namespace std;

vector<Particle> getData(string csvFileName){
    vector<Particle> particles;
    
    string initialVelocity;
    string angle;
    string initialPositionY;

    ifstream ip(csvFileName);

    if (!ip.is_open()){
        cout << "Error: File Open" << endl;
    }
    
    while (ip.good()){
        getline(ip,initialVelocity,',');
        getline(ip,angle,',');
        getline(ip,initialPositionY,'\n');

        double v0 = stod(initialVelocity);
        double theta = stod(angle);
        double y0 = stod(initialPositionY);

        Particle particle(v0, theta, y0);
        particles.push_back(particle);
    }

    ip.close();

    return particles;
}