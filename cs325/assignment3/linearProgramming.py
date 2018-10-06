import os
import sys
import math
from pulp import *

points = [(1,3), (2,5), (3,7), (5,11), (7,14), (8,15), (10,19)]
######################################################################
#                                                                    #
#                                                                    #
#                               Functions                            #
#                                                                    #
#                                                                    #
######################################################################
#Calculating slope
def calcSlope(x1, x2, y1, y2):
    return (float((y1 - y2))/float((x1 - x2)))

#Splitting the points list into x and y list
def splitPoints(pointsList):
    xList = []
    yList = []
    for point in pointsList:
        xList.append(point[0])
        yList.append(point[1])

    return [xList, yList]

#Finding the min and max slope for constraints.
def slopeMaxMin(xpoints, ypoints):
    slope = calcSlope(xpoints[0], xpoints[1], ypoints[0], ypoints[1])
    maxSlope = slope
    minSlope = slope
    for i in range(len(xpoints)):
            for j in range(i + 1,len(xpoints)):
                slope = calcSlope(xpoints[i], xpoints[j], ypoints[i], ypoints[j])
                if(slope > maxSlope):
                    maxSlope = slope
                elif(slope < minSlope):
                    minSlope = slope

    return [maxSlope, minSlope]

#######################################################################
#                                                                     #
#                                                                     #
#                            Main program                             #
#                                                                     #
#                                                                     #
#######################################################################
#Splitting the points list and finding the slopes.
xySplit = splitPoints(points)
slopes = slopeMaxMin(xySplit[0], xySplit[1])

#Creating the problem variable. Solving for the least absolute deviation line.
LADline = LpProblem("Linear regression", LpMaximize)

#Creating the variables a and b, for max |ax_i + b - y_i|
a = LpVariable("a", 0, cat="Continuous")
b = LpVariable("b", 0, cat="Continuous")

#Variable for absolute value
Z = LpVariable("Z", 0, cat="Continuous")

#splitting the coordinates
xcoords = xySplit[0]
ycoords = xySplit[1]

LADline += Z

for i in range(len(points)):
    LADline += a + xcoords[i] + b - ycoords[i] <= Z
    LADline += a + xcoords[i] + b - ycoords[i] >= Z

LADline += a <= slopes[0]
LADline += a >= slopes[1]

status = LADline.solve()

print(str(value(a)))
print(str(value(b)))
