import serial
import matplotlib.pyplot as plt
from drawnow import *
import atexit
from serial import Serial

values = []
values2 = []

plt.ion()
cnt=0

serialArduino = serial.Serial('/dev/ttyACM0', 9600)
#ax=[0,0,0,0,0,0]
#fig = plt.figure()

#ax[1] = fig.add_subplot(411)
#ax[2] = fig.add_subplot(412)
#ax[3] = fig.add_subplot(413)
#ax[4] = fig.add_subplot(414)

def plotValues(id):
    plt.subplot(4,1,id+1)
    plt.title('Serial value from Arduino'+str(id))
    plt.grid(True)
    #plt.ylabel('Values')
    plt.plot(values[i], 'rx-', label='values')
    #plt.legend(loc='upper right')

def doAtExit():
    serialArduino.close()
    print("Close serial")
    print("serialArduino.isOpen() = " + str(serialArduino.isOpen()))

# atexit.register(doAtExit)

print("serialArduino.isOpen() = " + str(serialArduino.isOpen()))


values = [[0]*26]*26
    
while True:
    while (serialArduino.inWaiting()==0):
        pass
    # print("readline()")
    valueRead = serialArduino.readline(500)
    rowValues = valueRead.split(",")[:-1]
    print(rowValues)
    #check if valid value can be casted
    try:
        rowValues = (map(int, rowValues))
        i = 0
        for prstr in rowValues:
            pr = int(prstr)
            if pr <= 1024:
                if pr >= 0:
                    values[i].append(pr)
                    values[i].pop(0)id=i)
                else:
                    print("Invalid! negative number")
            else:
                print("Invalid! too large")
            i=i+1

#        pr1 = int(rowValues[0])
#        pr2 = int(rowValues[1])
#        pr3 = int(rowValues[2])
#        pr4 = int(rowValues[3])
        """
        if pr1 <= 1024:
            if pr1 >= 0:
                values.append(pr1)
                values.pop(0)
                drawnow(plotValues)
            else:
                print("Invalid! negative number")
        else:
            print("Invalid! too large")

        if pr2 <= 1024:
            if pr2 >= 0:
                values2.append(pr2)
                values2.pop(0)
                drawnow(plotValues)
            else:
                print("Invalid! negative number")
        else:
            print("Invalid! too large")    

        if pr3 <= 1024:
            if pr3 >= 0:
                values3.append(pr3)
                values3.pop(0)
                drawnow(plotValues)
            else:
                print("Invalid! negative number")

        if pr4 <= 1024:
            if pr4 >= 0:
                values4.append(pr4)
                values4.pop(0)
                drawnow(plotValues)
            else:
                print("Invalid! negative number")
        else:
            print("Invalid! too large") 
        """
    except:
        continue
