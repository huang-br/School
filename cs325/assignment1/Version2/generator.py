import os
import sys
import random

length = int(sys.argv[1])
lines = int(sys.argv[2])
charlist = ['A', 'G', 'T', 'C']

fo = open("input.txt", "wb")

for i in range(lines):
	for j in range(length):
		fo.write(random.choice(charlist))

	fo.write(',')

	for j in range(length):
		fo.write(random.choice(charlist))

	fo.write('\n')


fo.close()
