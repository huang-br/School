#added the creation of copies of lines to be rotated.
def kwic(string, ignoreWords = [], listPairs = False, periodsToBreaks = False):
	string = string.lower()
	newlinesplit = [i.split(',') for i in string.split('\n')]
	for j in newlinesplit:
		j[0] = j[0].split()	

	wordsplitlist = newlinesplit
	index = 0
	for k in wordsplitlist:
		k.append(index)
		index += 1
	
	kwiclist = []
	for l in wordsplitlist:
		length = len(l[0])
		holdlist = [l]
		kwiclist += length * holdlist
	
	print(kwiclist)
	return kwiclist
