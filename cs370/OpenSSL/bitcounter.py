import sys
import os

def parse(hashString):
	splitString = hashString.split()
	hexVal = int(splitString[1],16)
	binVal = bin(hexVal)
	return binVal[2:]

def findDifference(firstHash, secondHash):
	counter = 0
	size = len(firstHash)
	if(len(secondHash) < size):
		size = len(secondHash)

	for i in range(size):
		if(firstHash[i] == secondHash[i]):
			counter += 1

	return float(counter)/len(firstHash)


with open(sys.argv[1]) as f:
	firstHash = f.readline()
f.close

with open(sys.argv[2]) as f:
	secondHash = f.readline()
f.close

hash1 = parse(firstHash)
hash2 = parse(secondHash)
percentSame = str(100-(findDifference(hash1, hash2) * 100))
print(percentSame + "%")
