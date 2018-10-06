#testing the sorting of the final array.
import kwic

teststring = "c\nb\na\nz"

result = kwic.kwic(teststring)

print(result[0][0])

assert(result[0][0] == ['a'])
print("PASS")
