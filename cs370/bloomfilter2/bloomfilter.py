import os
import sys
import hashlib
import time

####################################################################
#                          Functions                               #
####################################################################

#Using three hash functions to fill bloomfilter.
def threeHash(passwordList, bloomfilter, size):				
	bits = list()								#Creating an empty list to store the bits that are hashed to one.
	for password in passwordList:
		b1 = hashlib.sha1()						#Creating the hash objects
		b2 = hashlib.sha224()
		b3 = hashlib.sha256()
		
		b1.update(password)						#Hasing the passwords
		b2.update(password)
		b3.update(password)
		
		bits.append((int(b1.hexdigest(),16)%size))			#Hashing the passwords into hexidecimal values, then using modulus to find the array index.
		bits.append((int(b2.hexdigest(),16)%size))
		bits.append((int(b3.hexdigest(),16)%size))

		for bit in bits:						#Running through the array and setting all of the appropreate bits to 1.
			bloomfilter[bit] = 1

		del bits[:]							#clearing the list for the next password.

	return bloomfilter

#using five hash functions fo fill bloomfilter.
def fiveHash(passwordList, bloomfilter, size):					#Same process as the threeHash function. Just two extra passwords added.
	bits = list()
	for password in passwordList:
		b1 = hashlib.sha1()
		b2 = hashlib.sha224()
		b3 = hashlib.sha256()
		b4 = hashlib.sha384()
		b5 = hashlib.sha512()
		b1.update(password)
		b2.update(password)
		b3.update(password)
		b4.update(password)
		b5.update(password)
		
		bits.append((int(b1.hexdigest(),16)%size))
		bits.append((int(b2.hexdigest(),16)%size))
		bits.append((int(b3.hexdigest(),16)%size))
		bits.append((int(b4.hexdigest(),16)%size))
		bits.append((int(b5.hexdigest(),16)%size))

		for bit in bits:
			bloomfilter[bit] = 1

		del bits[:]

	return bloomfilter

#hashes the password to be checked, then checks them against the bloomfilter.
#if there is even 1 bit set then it is maybe. Otherwise it is no.
def threeCheck(checkList, bloomfilter, size):					
	bits = list()								#Creating Empty list for the bits that will be set.
	fo = open("output3.txt","wb")						#Creating the file. Will overwrite if it already exists.
	for password in checkList:						
		counter = 0							#setting a counter to zero. Will reset with every password 
		b1 = hashlib.sha1()						#hasing the passwords.	
		b2 = hashlib.sha224()
		b3 = hashlib.sha256()
		b1.update(password)						
		b2.update(password)
		b3.update(password)
		bits.append((int(b1.hexdigest(),16)%size))
		bits.append((int(b2.hexdigest(),16)%size))
		bits.append((int(b3.hexdigest(),16)%size))

		for bit in bits:						#Checking to see if any of the bits match in the bloomfilter.
			if(bloomfilter[bit] == 1):
				counter += 1

		if(counter == 0):						#If none of the bits match, then the password is defenately not in the bloomfilter.
			fo.write("no")
		else:
			fo.write("maybe")					#if even one of the bits match, then it might be in the bloomfilter.
		fo.write('\n')

		del(bits[:])
	
	fo.close()								#ends writing file.

#hashes the password to be checked, then checks them against the bloomfilter.
#if there is even 1 bit set then it is maybe. Otherwise it is no.
def fiveCheck(checkList, bloomfilter, size):					#same as the threeCheck function, just with two more passwords.
	bits = list()
	fo = open("output5.txt","wb")
	for password in checkList:
		counter = 0
		b1 = hashlib.sha1()
		b2 = hashlib.sha224()
		b3 = hashlib.sha256()
		b4 = hashlib.sha384()
		b5 = hashlib.sha512()
		b1.update(password)
		b2.update(password)
		b3.update(password)
		b4.update(password)
		b5.update(password)
		bits.append((int(b1.hexdigest(),16)%size))
		bits.append((int(b2.hexdigest(),16)%size))
		bits.append((int(b3.hexdigest(),16)%size))
		bits.append((int(b4.hexdigest(),16)%size))
		bits.append((int(b5.hexdigest(),16)%size))

		for bit in bits:
			if(bloomfilter[bit] == 1):
				counter += 1

		if(counter == 0):
			fo.write("no")
		else:	
			fo.write("maybe")
		fo.write('\n')

		del bits[:]

	fo.close()






#####################################################################
#                            main                                   #
#####################################################################
start = time.time()								#starting a timer
size = pow(2,22)								#Setting the size of the bloom filter.
with open(sys.argv[1]) as f:							#opening and reading the file. Reading all the passwords into a list.
	badPasswords = f.readlines()	
f.close()
passwordList = [passwords.strip() for passwords in badPasswords]
print "Time to read in the dictionary:",time.time() - start

fiveHashBloomfilter = [0] * size						#creating the two bloom filter. One using five hashes, and the other using three hashes.
threeHashBloomfilter = [0] * size

bloomStart = time.time()
threeHashBloomfilter = threeHash(passwordList, threeHashBloomfilter, size)	#hashing and filling the bloom filter using dictionary.txt
fiveHashBloomfilter = fiveHash(passwordList, fiveHashBloomfilter, size)	
print "Time to create the bloom filters:", time.time() - bloomStart

inputStart = time.time()
with open(sys.argv[2]) as f:							#reading in the input file
	checkPasswords = f.readlines()
f.close()
checkList = [check.strip() for check in checkPasswords]
checkListSize = checkList.pop(0)						#poping off the fisrt line, for the size of the list.
print "Time to read in the input:",time.time() - inputStart

output3start = time.time()
threeCheck(checkList, threeHashBloomfilter, size)				#generating the two output files
print "Time for three hash output:",time.time() - output3start
output5start = time.time()
fiveCheck(checkList, fiveHashBloomfilter, size)
print "Time for five hash output:", time.time() - output5start
print "time elapsed:",time.time() - start					#ending timer.

