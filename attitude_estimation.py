import numpy as np
from datetime import datetime

## roll fi, pitch theta

def roll_angle(Gpy, Gpz):
    fi = np.arctan2(Gpy, Gpz)*180/np.pi ## converting to arctan and rad to grad
    
    return round(fi, 4)

def pitch_angle(Gpx, Gpy, Gpz):
    pitch = (-Gpx)/np.sqrt(Gpy**2+Gpz**2) 
    theta = np.arctan(pitch)*180/np.pi ## converting to arctan and rad to grad
    
    return round(theta, 4)

## Organizating the data 

data = []
organizated = []
attitude = 'attitude_exam.log'

with open(attitude) as f:
    f = f.readlines()

for line in f:
    for phrase in line:
        data.append(line)
        break

organizated = [element.strip().split(';') for element in data]

## calculating all the angles

for i in organizated:
    time_stamp = datetime.fromtimestamp(int(i[0]))
    Gpx = int(i[1])
    Gpy = int(i[2])
    Gpz = int(i[3])

    print('For time: '  , time_stamp)
    print('Gpx, Gpy and Gpz: ')
    print(Gpx)
    print(Gpy)
    print(Gpz)
    print('Rolls angles: ')
    fi = roll_angle(Gpy, Gpz)
    print(fi)
    print('Pitch angle: ')
    theta = pitch_angle(Gpx, Gpy, Gpz)
    print(theta)
    print('\n')
    
    