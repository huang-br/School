import os
import sys

fn = "imp2input.txt"
if(os.path.isfile(fn) == False):
	print("invalid File")
	sys.exti()

seq = []
with open (fn, 'r') as f:
	for l in f:
		seq.append(l)


print seq
