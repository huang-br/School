#test for converting the final data into tuples
import kwic

teststring = "this is a test"

result = kwic.kwic(teststring)

assert(type(result[0]) is tuple)
print("PASS")
