#testing rotation
import kwic

teststring = "The rotation test\n The second rotation test"

result = kwic.kwic(teststring)

zeroRotation = ['The', 'rotation', 'test']

assert(result[0][0] != zeroRotation)
print("PASS")
