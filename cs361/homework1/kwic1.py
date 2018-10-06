#added newline splits and indicies
def kwic(string, ignoreWords = [], listPairs = False, periodsToBreaks = False):
	string = string.lower()
	newlinesplit = [i.split(',') for i in string.split('\n')]
	for j in newlinesplit:
		j[0] = j[0].split()	

	kwiclist = (newlinesplit)
	index = 0
	for k in kwiclist:
		k.append(index)
		index += 1

	print(kwiclist)
	return kwiclist
