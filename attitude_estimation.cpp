#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

double roll_angle(double Gpy, double Gpz) {
    double fi = atan2(Gpy, Gpz)*180/M_PI; // converting to arctan and rad to grad
    
    return round(fi, 4);
}

double pitch_angle(double Gpx, double Gpy, double Gpz) {
    double pitch = (-Gpx)/sqrt(pow(Gpy, 2)+pow(Gpz, 2)); 
    double theta = atan(pitch)*180/M_PI; // converting to arctan and rad to grad
    
    return round(theta, 4);
}

int main() {
    
}