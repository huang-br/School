import os
import sys
import math

points = [(1,3),(2,5),(3,7),(5,11),(7,14),(8,15),(10,19)]

def calculateLine(pointsList):
	#initializing variables
	xSum = 0
	xSquareSum = 0
	ySum = 0
	mulSum = 0
	numerator = 0
	denominator = 0
	slope = 0
	intercept = 0
	#calculating slope
	for point in pointsList:
		mulSum += (point[0] * point[1])
		xSum += point[0]
		xSquareSum += (point[0] * point[0])
		ySum += point[1]

	numerator = mulSum - ((xSum * ySum)/len(pointsList))
	denominator = xSquareSum - (pow(xSum, 2)/len(pointsList))
	print(numerator)
	print(denominator)
	slope = float(numerator)/float(denominator)

	#calculating intercept
	intercept = (ySum - (slope * xSum))/len(pointsList)

	return [slope, intercept]

s = calculateLine(points)

print(s)
