import os
import sys
import time
from math import pow
from math import sqrt

def reverse(string):
	return string[::-1]

#x,y dna to compare, cost chart
def calc(x,y,cost):
	if (x == 'A'):
		xA = 2
	elif (x == 'T'):
		xA = 3
	elif (x == 'G'):
		xA = 4
	elif (x == 'C'):
		xA = 5
	else:
		xA = 1
	if (y == 'A'):
		yA = 2
	elif (y == 'T'):
		yA = 3
	elif (y == 'G'):
		yA = 4
	elif (y == 'C'):
		yA = 5
	else:
		yA = 1
	tot = yA * 6 + xA
	return int(cost[tot])
	
#Find minimum changes to convert s1 to s2
def findDistance(s1,s2,d1,d2,cost):
	strMat = [[0 for y in range(d2+1)] for y in range(d1+1)]
	matrix = [[0 for x in range(d2+1)] for x in range(d1+1)]
	for i in range(d1+1):
		for j in range(d2+1):
			if i == 0:
				cTot = 0
				for te in range (j-1):
					cTot = cTot + calc(s2[te],'-',cost)
				matrix[i][j] = cTot  
			elif j==0:
				cTol = 0
				for tm in range (i-1):
					cTol = cTol + calc(s1[tm],'-',cost)
				matrix[i][j] = cTol
			elif s1[i-1] == s2[j-1]:
				matrix[i][j] = matrix[i-1][j-1] + calc(s1[i-1], s2[j-1], cost)
			else:
				insertion = matrix[i][j-1]
				remove = matrix[i-1][j]
				substitution = matrix[i-1][j-1] 
				matrix[i][j] = calc(s1[i-1], s2[j-1], cost) + min(insertion, remove, substitution)

	return matrix[d1][d2]

def editDistance(s1, s2, l1, l2):
	matrix = [[0 for x in range(l2 + 1)] for x in range(l1 + 1)]
	for i in range(l1 + 1):
		for j in range(l2 + 1):
			if i == 0:
				matrix[i][j] = j
			elif j == 0:
				matrix[i][j] = i
			elif s1[i-1] == s2[j-1]:
				matrix[i][j] = matrix[i-1][j-1]
			else:
				insertion = matrix[i][j-1]
				remove = matrix[i-1][j]
				substitution = matrix[i-1][j-1]
				minimum = min(insertion, remove, substitution)
				matrix[i][j] = 1 + minimum

	return matrix


def findPath(matrix, s1, s2, l1, l2):
	string1 = ""
	string2 = ""
	x = l1
	y = l2
	stepList = []
	package = []
	stepList.append((x,y))
	for i in range(max(l1, l2)):
		insertion = matrix[x][y-1]
		remove = matrix[x-1][y]
		substitution = matrix[x-1][y-1]
		minimum = min(insertion, remove, substitution)
		if(minimum == substitution):
			x -= 1
			y -= 1
			string1 += s2[y]
			string2 += s2[y]
			stepList.append((x,y))
			
		elif(minimum == remove):
			x -= 1
			stepList.append((x,y))
			string1 += s1[x]
			string2 += '-'
		elif(minimum == insertion):
			y -= 1
			stepList.append((x,y))
			string1 += '-'
			string2 += s2[y]

	stepList.pop()

	package.append(reverse(string1)) 
	package.append(reverse(string2))
	return package

def findCost(steps, s1, s2, cost):
	totalCost = 0
	for i in steps:
		totalCost += calc(s1[i[0] - 1], s2[i[1] - 1], cost)

	return totalCost

#a1 1st DNA sequence, a2 2nd DNA sequence, cost chart
def findMin(a1,a2,cost):
	fin = ""
	Di = []
	Dj = []
	cMin = 0
	cMin = findDistance(a1,a2,len(a1),len(a2),cost)
	strings = findPath(editDistance(a1, a2, len(a1), len(a2)), a1, a2, len(a1), len(a2))
	fin = strings[0] + ',' + strings[1] + ':' + str(cMin)
	print(fin)
	return fin	

#read input file
fn = "imp2input.txt"
if(os.path.isfile(fn) == False):
	print("Invalid input file")
	sys.exit()

#Put input file into list
seq = []
with open (fn, 'r') as f:
	for l in f:
		seq.append(l)

#Put costs into list
fl = "imp2cost.txt"
if(os.path.isfile(fl) == False):
	print("Invalid cost file")
	sys.exit()

cost = []
with open(fl, 'r') as f:
	c = f.read()
	c = c.replace('\n',',')
	cost = c.split(',')

start = time.time()
output = []
for i in range(0,len(seq)):
	dnaStr = seq[i]
	dnaStr.replace('\n','')
	dnaSplit = dnaStr.split(',')
	output.append(findMin(dnaSplit[0],dnaSplit[1].rstrip(),cost))
	output.append('\n')
fo = open("output.txt","wb")
strOutput = ''.join(str(w) for w in output)
strOutput.replace(' ','')
fo.write(strOutput)
fo.write("\n")
print "Time to calculate minimum cost: ", time.time() - start
fo.close()
