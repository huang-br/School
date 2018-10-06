def numChanger(num, listOnums):
	num += 10
	listOnums[0] += 1
	listOnums[1] += 2
	listOnums[2] += 3

	return[num,listOnums]

def Addone(x):
	x = x + 1
	print x

check = list()
check.append(list())
check.append(list())

print check

testInt = 10
testList = [0,1,2]

print [testInt, testList]

print numChanger(testInt, testList)

charList = ['1','2','3','4','5']

numList = map(lambda x: int(x), charList)

print numList

print(type(numList[0]))

x = 10

print x

Addone(x)

print x
