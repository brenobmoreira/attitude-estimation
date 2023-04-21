import numpy as np

## roll fi, pitch theta

def pitch_angle(Gpy, Gpz):
    return np.arctan(Gpy/Gpz)


data = []
attitude = 'attitude_exam.log'

with open(attitude) as f:
    f = f.readlines()

#for line in f:
#    for phrase in line:
#        data.append(line)
#        break

for i in data:
    adad


print(data)