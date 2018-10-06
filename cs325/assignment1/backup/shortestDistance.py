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

def bruteforce(pointslist):
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

if(sys.argv[1] == "bruteforce"):
	data = bruteforce(points)
	data[1] = sorted(data[1])

	fo = open("output.txt","wb")

	fo.write(str(data[0]))
	fo.write("\n")
	for pairs in data[1]:
		fo.write(pairsToString(pairs))
		fo.write("\n")

	fo.close()

else:
	print("Invalid method")
	print("Usage: python shortestDistance.py <method> <textfile>")
