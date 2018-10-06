#testing for ignored words
import kwic

teststring = "bannana should never\n be the first word. bannana."

result = kwic.kwic(teststring, ignoreWords = ["bannana"])

assert(result[0][0] != "bannana")
print("PASS")


