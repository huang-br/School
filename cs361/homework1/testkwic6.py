#testing for changing ignorewords to all lower
import kwic

teststring = "The word apple should be ignored."

result = kwic.kwic(teststring, ignoreWords = ['APPLE'])
assert(result[0][0] != 'apple')
print("PASS")
