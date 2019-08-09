#!/usr/bin/python

import serial
import time
import sys

fileOut = sys.argv[2]
port = sys.argv[1]

f = open(fileOut, "w")

ser = serial.Serial(port, 9600, timeout=1)

def getData(timeout, label):
    timeI = time.time()
    while time.time()-timeI < timeout:
        try:
            reading = ser.readline()
            pr = [0,0,0,0,0,0,0,""]
            pr[0] = time.time()-timeI
            pr[1] = time.time()
            pr[2] = int(reading.split('\n')[0].split(",")[0])
            pr[3] = int(reading.split('\n')[0].split(",")[1])
            pr[4] = int(reading.split('\n')[0].split(",")[2])
            pr[5] = int(reading.split('\n')[0].split(",")[3])
            pr[6] = int(reading.split('\n')[0].split(",")[4])
            pr[7] = label
            for i in pr:
                print str(i)+",",
                f.write(str(i)+",")
            print ""
            f.write("\n")
        except:
            pass

gestures = ["fist", "extend", "one", "two", "three", "four", "five", "spiderman", "vulcan", "index in", "middle in", "ring in", "little in", "thumb in", "lift up", "lift down"]

print("delta Time, Unix Time, pr1, pr2, pr3, pr4, pr5, label")
f.write("delta Time, Unix Time, pr1, pr2, pr3, pr4, pr5, label\n")

for gesture in gestures:
    continueQ = raw_input("Do "+gesture+"? [Y/n]: ")
    if continueQ == "y" or continueQ == "" or continueQ == "Y":
        getData(5.0, gesture)
    elif continueQ == "n" or continueQ == "N":
        continueQ = "n"
    
f.close()
