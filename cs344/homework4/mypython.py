import string
import random

for x in range(3):
	mystring = ""
	name = "file" + str(x)
	file = open(name, 'w+')
	for y in range(10):
		mystring += (random.choice(string.lowercase))
	file.write(mystring + "\n")
	file.close()
	print(mystring)


first = random.choice(range(1,43))
second = random.choice(range(1,43))
product = first * second
print first, second
print "The product of these two numbers is:", product

