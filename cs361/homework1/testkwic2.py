#testing the creation of multiple of the same lines

import kwic

teststring = "The length of the array should be 8"

result = kwic.kwic(teststring)

assert(len(result) == 8)
print("PASS")

