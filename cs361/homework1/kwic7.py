#added periods to breaks.
def rotate(l,n):
	return l[-n:] + l[:-n]

def kwic(string, ignoreWords = [], listPairs = False, periodsToBreaks = False):
	string = string.lower()
	for h in range(len(ignoreWords)):
		ignoreWords[h] = ignoreWords[h].lower()

	if periodsToBreaks == True:
		newlinesplit = [i.split(',') for i in string.split('. ')]
		for j in newlinesplit:
			j[0] = j[0].split()

	else:
		newlinesplit = [i.split(',') for i in string.split('\n')]
		for j in newlinesplit:
			j[0] = j[0].split()	

	kwiclist = []
	index = 0
	counter = 0
	for l in newlinesplit:
		length = len(l[0])
		for m in range(length):
			kwiclist.append([rotate(l[0],m)])
			kwiclist[counter + m].append(index)

		index += 1
		counter += length

	for n in kwiclist:
		if n[0][0] in ignoreWords:
			kwiclist.remove(n)
		else:
			pass

	kwiclist.sort()

	print(kwiclist)
	return kwiclist
