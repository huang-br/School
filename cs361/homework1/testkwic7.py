#tests for periodsToBreaks
import kwic

teststring = "Line one. Line two."

result = kwic.kwic(teststring, periodsToBreaks = True)
assert(len(result) == 4)
print("PASS")
