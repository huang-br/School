import hmac
import time
import hashlib
import math
import threading

#Following RFC4226 HOTP algorithm description.
#Step 1: Generate 20 byte string
#Step 2: Generate a 4 byte string by using dynamic truncation.
#Step 3: Generate the TOTP value.

def DynamicTruncate(hmac_sha):
	offset = int(hmac_sha[-1],16)					#Setting the offset as the last nibble of the HMAC-SHA1 string
	binString = ""							#Creating a blank string for the dynamic string generation.
	for i in range(0,8):						#Creating the string from the offset.
		binString += hmac_sha[offset + i]
	binString = int(binString,16)					#Converting from hex to dec.
	binString = bin(binString)[2:]					#Converting from dec to bin.
	return '0' + binString[1:]					#Masking the first bit as 0. Returns 0 + 31bits of the truncated string. 

def TOTP(key):
	timestamp = math.floor(time.time() / 30)				#Using a unix time divided by thirty, then floored for the message.
	HS = hmac.new(key, str(timestamp), hashlib.sha1).hexdigest()		#Creating the a HMAC-SHA1 20-byte string
	Sbits = int(DynamicTruncate(HS),2)					#Uses Dynamic Truncation to create a 4-byte string.
	D = str(Sbits % pow(10, 6))						#Using modulo to generate the TOTP value.
	
	while(len(D) < 6):							#Appending 0's to the end of the string if it is not long enough.
		D += '0'
	
	print(D)

start = time.time()
key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"					#Creating the shared key.
print "Key:", key							#Print out the key.

while(1):
	TOTP(key)
	time.sleep(30)
