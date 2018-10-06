import os
import sys
from math import pow
from math import sqrt

#finds the distance between two points
#returns a float
def findDistance(p1, p2):
	num = (pow((p1[0] - p2[0]),2) + (pow((p1[1] -  p2[1]),2)))
	return sqrt(num)

#Converts a pair of points into a string.
#returns a string that looks like: <number 1> <number 2>
def pairsToString(pointsList):
	coordList=[]
	for point in pointsList:
		for coordinate in point:
			coordList.append(str(coordinate))

	finalString = " "
	finalString = finalString.join(coordList)

	return finalString

#Finds the closest distance according of two points according to the y coordinate
#returns a float
def closestInStrip(pointsList, d):
	minDistance = d
	ysorted = sorted(pointsList, key = lambda x: x[1])
	for i in range(len(ysorted)):
		for j in range((i+1), len(pointsList)):
			if(findDistance(pointsList[i], pointsList[j]) < minDistance):
				minDistance = findDistance(pointsList[i], pointsList[j])
	
	return minDistance

#used to find pairs that have distance d between them
#returns a list of lists that have a pair of tuples. [[(x1,y1),(x2,y2)],.....[(xn-1, yn-1),(xn, yn)]]
def findPairs(pointsList, d):
	pairList = []
	pair = []
	for firstPoint in range(len(pointsList)):
		for secondPoint in range(firstPoint + 1, len(pointsList)):
			if(findDistance(pointsList[firstPoint], pointsList[secondPoint]) == d):
				pair = list(pair)
				del pair[:]
				pair.extend((pointsList[firstPoint], pointsList[secondPoint]))
				pairList.append(pair)

	return pairList

#enhanced divide and couquer method. Uses pre-sorted list of points to find the shortest distance.
#returns a float.
def enhanceddnc(pointslist):
	arraylen = len(pointslist)
	if(arraylen <= 3):
		return bruteforce(pointslist)

	median = arraylen/2 #the right array will have one more emelent than the left if the arraylen is odd.
	mid = pointslist[median]
	xL = enhanceddnc(pointslist[:median])
	xR = enhanceddnc(pointslist[median:])
	d = min(xL, xR)

	strip = []
	for i in pointslist:
		if(abs((i[0] - mid[0]) < d)):
			strip.append(i)
	
	stripDistance = closestInStrip(strip, d)
	return min(stripDistance,d)

#Bruteforce method for finding the shortest distance.
#returns a float
def bruteforce(pointslist):
	shortestDistance = 0
	for i in range(len(pointslist)):
		for j in range(i + 1, len(pointslist)):
			distance = findDistance(pointslist[i],pointslist[j])
			if(i == 0 and j == 1):
				shortestDistance = distance
			elif(distance < shortestDistance):
				shortestDistance = distance

	return shortestDistance

####program starts here####

#error handling for not enough arguments
if(len(sys.argv) < 3):
	print("Not enough arguments")
	print("Usage: python shortestDistance.py <method> <textfile>")
	print("Methods: bruteforce, divideandconquer, enhanceddnc")
	sys.exit()

#reads in the file and puts all the points into a list.
fn = sys.argv[2]
if(os.path.isfile(fn) == False):
	print("Invalid file name")
	print("Usage: pyhton shortestDistance.py <method> <textfile>")
	print("Methods: bruteforce, divideandconquer, enhanceddnc")
	sys.exit()

points = []
with open(fn, 'r') as f:
	for l in f:
		ls = l.split()
		pair =[]
		for n in ls:
			pair.append(float(n))
			tuplepair = tuple(pair)

		points.append(tuplepair)

#If the bruteforce method is called.
if(sys.argv[1] == "bruteforce"):
	shortestLength = bruteforce(points)
	pairList = findPairs(points, shortestLength)
	pairList = sorted(pairList)

	fo = open("output.txt","wb")
	fo.write(str(shortestLength))
	fo.write("\n")
	for pairs in pairList:
		fo.write(pairsToString(pairs))
		fo.write("\n")

	fo.close()


#If the enhanceddnc is called
elif(sys.argv[1] == "enhanceddnc"):
	xsorted = sorted(points)
	shortestLength = enhanceddnc(xsorted)
	pairList = findPairs(xsorted, shortestLength)
	pairList = sorted(pairList)

	fo = open("output.txt", "wb")	
	fo.write(str(shortestLength))
	fo.write("\n")
	for pairs in pairList:
		fo.write(pairsToString(pairs))
		fo.write("\n")

	fo.close()

#error handling for an invalid input.
else:
	print("Invalid input, check spelling or the name of the file.")
	print("Usage: python shortestDistance.py <method> <textfile>")
	print("Methods: bruteforce, divideandconquer, enhanceddnc")
	sys.exit()
