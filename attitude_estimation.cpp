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

    ofstream data_save("pitch_and_roll_angles_c++.csv");
    data_save << "data,roll(fi) angle,pitch(theta) angle\n";
    
    vector<string> data;
    vector<vector<string>> organizated;
    
    // open the log
    ifstream file;
    string line;

    file.open("attitude_exam.log"); 
    if (file.is_open()) {
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    for (const auto& element : data) {
        vector<string> temp;
        size_t start = 0;
        size_t end = 0;

        while ((end = element.find(';', start)) != string::npos) {
            temp.push_back(element.substr(start, end-start));
            start = end + 1;
        }

        temp.push_back(element.substr(start));
        organizated.push_back(temp);
    }

    for (const auto& i : organizated) {
        
        time_t time_stamp = stoi(i[0]);
        double Gpx = stod(i[1]);
        double Gpy = stod(i[2]);
        double Gpz = stod(i[3]);
        
        cout << "For time: " << ctime(&time_stamp);
        cout << "Gpx, Gpy and Gpz" << endl;
        cout << i[1] << endl;
        cout << i[2] << endl;
        cout << i[3] << endl;
        cout << "Roll angle:" << endl;

        double fi = roll_angle(Gpy, Gpz);
        cout << fi << endl; 

        cout << "Pitch angle:" << endl;
        double theta = pitch_angle(Gpx, Gpy, Gpz);
        cout << theta << endl;
        cout << "\n" << endl;

        string time_str = ctime(&time_stamp);
        data_save << time_str + "," << fi << "," << theta << "\n";
    }
     
    data_save.close();

    return 0;
}
