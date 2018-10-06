import os
import sys
from math import pow
from math import sqrt

def findDistance(p1, p2):
	num = (pow((p1[0] - p2[0]),2) + (pow((p1[1] -  p2[1]),2)))
	return sqrt(num)

def pairsToString(pointsList):
	coordList=[]
	for point in pointsList:
		for coordinate in point:
			coordList.append(str(coordinate))

	finalString = " "
	finalString = finalString.join(coordList)

	return finalString

def closestInStrip(pointsList, d):
	minDistance = d
	ysorted = sorted(pointsList, key = lambda x: x[1])
	for i in range(len(ysorted)):
		for j in range((i+1), len(pointsList)):
			if(findDistance(pointsList[i], pointsList[j]) < minDistance):
				minDistance = findDistance(pointsList[i], pointsList[j])
	
	return minDistance

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

#fuck everything. Finds just the distance. return it. bruteforce pairs with matching length. output in desired format.
def delta(pointslist):
	arraylen = len(pointslist)
	if(arraylen <= 3):
		return bruteforce(pointslist)

	median = arraylen/2 #the right array will have one more emelent than the left if the arraylen is odd.
	mid = pointslist[median]
	xL = delta(pointslist[:median])
	xR = delta(pointslist[median:])
	d = min(xL[0], xR[0])

	strip = []
	for i in pointslist:
		if(abs((i[0] - mid[0]) < d)):
			strip.append(i)
	
	stripDistance = closestInStrip(strip, d)

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

def oldbruteforce(pointslist):
	shortestDistance = 0
	shortestPairs = []
	pair = []
	newpair = []
	for i in range(len(pointslist)):
		for j in range(i + 1, len(pointslist)):
			distance = findDistance(pointslist[i],pointslist[j])
			if(i == 0 and j == 1):
				shortestDistance = distance
				pair.extend((pointslist[i], pointslist[j]))
				shortestPairs.append(pair)
			elif(distance < shortestDistance):
				shortestDistance = distance
				del pair[:]
				del shortestPairs[:]
				pair.extend((pointslist[i], pointslist[j]))
				shortestPairs.append(pair)
			elif(distance == shortestDistance):
				newpair = list(pair)
				del newpair[:]
				newpair.extend((pointslist[i],pointslist[j]))
				shortestPairs.append(newpair)
				
	info=[]
	info.extend((shortestDistance, shortestPairs))
	return info

def enhanceddnc(pointslist):
	arraylen = len(pointslist)
	median = arraylen/2 #the right side will have one more element than the left if arraylen is odd.
	print(delta(pointslist))
			
	#print(pointslist)
	#print midStrip


if(len(sys.argv) < 3):
	print("Not enough arguments")
	print("Usage: python shortestDistance.py <method> <textfile>")
	sys.exit()

fn = sys.argv[2]
points = []
with open(fn, 'r') as f:
	for l in f:
		ls = l.split()
		pair =[]
		for n in ls:
			pair.append(float(n))
			tuplepair = tuple(pair)

		points.append(tuplepair)

#if(sys.argv[1] == "bruteforce"):
#	data = bruteforce(points)
#	data[1] = sorted(data[1])
#
#	fo = open("output.txt","wb")
#
#	fo.write(str(data[0]))
#	fo.write("\n")
#	for pairs in data[1]:
#		fo.write(pairsToString(pairs))
#		fo.write("\n")
#
#	fo.close()

if(sys.argv[1] == "bruteforce"):
	shortestLength = bruteforce(points)
	pairList = findPairs(points, shortestLength)

	fo = open("output.txt","wb")
	fo.write(str(shortestLength))
	fo.write("\n")
	for pairs in pairList:
		fo.write(pairsToString(pairs))
		fo.write("\n")

	fo.close()


elif(sys.argv[1] == "enhanceddnc"):
	xsorted = sorted(points)
	ysorted = sorted(points, key = lambda x: x[1])

	enhanceddnc(xsorted)


else:
	print("Invalid method")
	print("Usage: python shortestDistance.py <method> <textfile>")
