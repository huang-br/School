import random
import os
import sys

low = sys.argv[1]
high = sys.argv[2]
size = sys.argv[3]

fo = open("input.txt", "wb")

for n in range(int(size)):
	fo.write(str(random.randint(int(low),int(high))))
	fo.write(" ")
	fo.write(str(random.randint(int(low),int(high))))
	fo.write("\n")

fo.close()
