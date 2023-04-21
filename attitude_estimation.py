import numpy as np

## roll fi, pitch theta

def roll_angle(Gpy, Gpz):
    roll = Gpy/Gpz
    fi = np.arctan(roll)*180/np.pi ## converting to arctan and rad to grad
    if(fi > 0):
        fi2 = 180 - fi
    else:
        fi2 = 180 + fi
    #print(Gpy/Gpz, ' -- Gpy/Gpz')
    #print(np.arctan(Gpy/Gpz)*180/np.pi, '--Arctan')
    return round(fi, 4), round(fi2, 4)

def pitch_angle(Gpx, Gpy, Gpz):
    pitch = (-Gpx)/np.sqrt(Gpy**2+Gpz**2) 
    theta = np.arctan(pitch)*180/np.pi ## converting to arctan and rad to grad
    
    #print(theta, ' -- -Gpx/sqrt(Gpy^2+Gpz^2)')
    #print(np.arctan(theta)*180/np.pi, '--Arctan')
    return round(theta, 4)


data = []
attitude = 'attitude_exam.log'

with open(attitude) as f:
    f = f.readlines()

#for line in f:
#    for phrase in line:
#        data.append(line)
#        break

Gpx = 0.461105
Gpy = 0.082198
Gpz = -0.887432
fi, fi2 = roll_angle(Gpy, Gpz)

print(fi, fi2)
print(pitch_angle(Gpx, Gpy, Gpz))

print(data)