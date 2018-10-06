#testing splitting the words in each line and adding the correct line number
import kwic

teststring = "This should have index 0\n and this should have index 1\n and finally this should have index 2"

result = kwic.kwic(teststring)
assert(result[0][1] == 0)
print("PASS")

