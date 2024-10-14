# -*- coding: utf-8 -*-
"""
Created on Mon Oct 14 12:30:42 2024

It works!

@author: Robin
"""
import numpy as np
import array as arr
import time as time
import matplotlib.pyplot as plt



def Amove(z):
    print (z ,"| A motor steps")
    
def Bmove(z):
    print (z ,"| B motor steps")

def deltaA(delX, delY):
    return delX + delY

def deltaB(delX, delY):
    return delX - delY

x = 5

def printall(x,y,nx,ny,xd,yd):
    print("")
    print("---------------------")
    print("")
    print("current position: ", x, " ", y)
    print("")
    print("new position: ", nx, " ", ny)
    print("")
    print("position differential: ", xd, " ", yd)
    print("")
    




def start():
    position_y = 0
    position_x = 0
    
    new_position_x = 0
    new_position_y = 0
    
    motorAmovement = 0
    motorBmovement = 0
    
    
    position_x_diff = new_position_x - position_x
    position_y_diff = new_position_y - position_y
    
    for i in range(x):
            
            new_position_x = np.random.randint(0,40)
            new_position_y = np.random.randint(0,40)
            position_x_diff = new_position_x - position_x
            position_y_diff = new_position_y - position_y
            printall(position_x , position_y, new_position_x, new_position_y, position_x_diff, position_y_diff)
            
            motorAmovement = deltaA(position_x_diff, position_y_diff)
            motorBmovement = deltaB(position_x_diff, position_y_diff)
            
            Amove(motorAmovement)
            Bmove(motorBmovement)
            print ("")
            print ("-----------------")
            print ("")
                
            position_x = new_position_x
            position_y = new_position_y
            time.sleep(1)
 
            i += i
start()
