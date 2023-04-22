#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;


double roll_angle(double Gpy, double Gpz) {
    double fi = atan2(Gpy, Gpz)*180/M_PI; // converting to arctan and rad to grad

    return fi;
}

double pitch_angle(double Gpx, double Gpy, double Gpz) {
    double pitch = (-Gpx)/sqrt(pow(Gpy, 2)+pow(Gpz, 2));
    double theta = atan(pitch)*180/M_PI; // converting to arctan and rad to grad

    return theta;
}

int main() {

    vector<string> data;
    vector<vector<string>> organizated;
    
    // open the log
    ifstream file;
    string line;

    file.open("attitude_exam.log"); 
    if (file.is_open()) {
        while (getline(file, line)) {
            data.push_back(line);
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    //double Gpx = 0.461105;
    //double Gpy = 0.082198;
    //double Gpz = -0.1;

    //double fi = roll_angle(Gpy, Gpz);
    //double theta = pitch_angle(Gpx, Gpy, Gpz);

    //cout << fi << endl;
    //cout << theta << endl;
    return 0;
}
