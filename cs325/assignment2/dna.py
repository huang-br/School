import os
import sys
import time
from math import pow
from math import sqrt

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
	return int(cost[yA][xA])

def 
#a1 1st DNA sequence, a2 2nd DNA sequence, cost chart
def findMin(a1,a2,cost):
	fin = []
	dna1 = ""
	dna2 = ""
	c = 0
	aD1 = list(a1)
	aD2 = list(a2)	
	for m in range(min(len(aD1),len(aD2))):
		c = c + calc(aD1[m],aD2[m],cost)
	
	fin.append(a1)
	fin.append(',')
	fin.append(a2.rstrip())
	fin.append(":")
	fin.append(str(c))
	strFin = ''.join(str(z) for z in fin)
	strFin.replace('\n','')
	print(strFin)
	return strFin

if(len(sys.argv) < 4):
	print("Not enough arguments")
	sys.exit()

#read input file
fn = sys.argv[1]
if(os.path.isfile(fn) == False):
	print("Invalid input file")
	sys.exit()

#Put input file into list
seq = []
with open (fn, 'r') as f:
	for l in f:
		seq.append(l)

#Put costs into list
fl = sys.argv[2]
if(os.path.isfile(fl) == False):
	print("Invalid cost file")
	sys.exit()

#cost = []
#with open(fl, 'r') as f:
#	c = f.read()
#	c = c.replace('\n',',')
#	cost = c.split(',')
#	print(cost)

#########################################
cost = []
with open(fl, 'r') as f:
	c = f.read().splitlines()
	cost = c

table = []
lines = []
for i in cost:
	lines = list(lines)
	lines = i.split(',')
	table.append(lines)

cost = table
#########################################

start = time.time()
output = []
for i in range(0,len(seq)):
	dnaStr = seq[i]
	dnaStr.replace('\n','')
	dnaSplit = dnaStr.split(',')
	output.append(findMin(dnaSplit[0],dnaSplit[1],cost))
	output.append('\n')
fo = open("output.txt","wb")
strOutput = ''.join(str(w) for w in output)
strOutput.replace(' ','')
fo.write(strOutput)
fo.write("\n")
print "Time to calculate minimum cost: ", time.time() - start
fo.close()
