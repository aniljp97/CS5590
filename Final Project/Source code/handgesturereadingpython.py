#hand gesture reading file

import subprocess
from picamera import PiCamera
from time import sleep
import sys
import math
import numpy

cameraImage = PiCamera()
cameraImage.start_preview()
sleep(5)
cameraImage.capture('test/cameraImage.jpg')
cameraImage.stop_preview()

subprocess.check_output(["octave", "--eval", "main"])

f = open("myfile.txt", "r")
f.readline()
f.readline()
f.readline()
result = f.readline().strip()

if(result == "1"):
    subprocess.call("epiphany-browser http://amazon.com", shell=True)
elif(result == "2"):
    subprocess.call("epiphany-browser http://msn.com", shell=True)
elif(result == "3"):
    subprocess.call("epiphany-browser http://umkc.edu", shell=True)
elif(result == "4"):
    subprocess.call("epiphany-browser http://google.com", shell=True)

    
