#testing list pairs
import kwic

teststring = "The quick brown fox\n jumped over the lazy fox"
result = kwic.kwic(teststring)
resultwithpairs = kwic.kwic(teststring, listPairs = True)

assert(len(resultwithpairs) == len(result) + 1)
print("PASS")


