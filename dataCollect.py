#!/usr/bin/python

import serial
import time



ser = serial.Serial('/dev/ttyACM1', 9600, timeout=1)

def getData(timeout, label):
    timeI = time.time()
    while time.time()-timeI < timeout:
        try:
            reading = ser.readline()
            pr = [0,0,0,0,0,0,0,""]
            pr[0] = time.time()-timeI
            pr[1] = time.time()
            pr[2] = reading.split('\n')[0].split(",")[0]
            pr[3] = reading.split('\n')[0].split(",")[1]
            pr[4] = reading.split('\n')[0].split(",")[2]
            pr[5] = reading.split('\n')[0].split(",")[3]
            pr[6] = reading.split('\n')[0].split(",")[4]
            pr[7] = label
            for i in pr:
                print str(i)+",",
            print ""
        except:
            pass

gestures = ["fist", "extend", "one", "two", "three", "four", "five", "spiderman"]

for gesture in gestures:
    continueQ = raw_input("Do "+gesture+"? [Y/n]: ")
    if continueQ == "y" or continueQ == "" or continueQ == "Y":
        getData(5.0, gesture)
    elif continueQ == "n" or continueQ == "N":
        continueQ = "n"
    
