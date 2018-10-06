#added pairing

def rotate(l,n):
	return l[-n:] + l[:-n]

def pair(source):
	result = []
	for p1 in range(len(source)):
		for p2 in range(p1+1, len(source)):
			result.append([source[p1],source[p2]])
	return result

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

	pairlist = []
	pairs = []
	for strings in newlinesplit:
		pairlist.append(pair(strings[0]))

	fill = 0
	for w in range(len(pairlist)):
		fill += 1
		for x in range(fill,len(pairlist)):
			for y in range(len(pairlist[w])):
				for z in range(len(pairlist[x])):
					if pairlist[w][y] == pairlist[x][z]:
						pairs.append(pairlist[w][y])
	uniq = []
	for x in pairs:
		if x not in uniq:
			uniq.append(x)

	count = []
	for x in uniq:
		num = 0
		for y in range(len(pairs)):
			if x == pairs[y]:
				num += 1
		count.append(num)
	
	finalpairlist = []
	for x in range(len(uniq)):
		finalpairlist.append([uniq[x]])

	for y in range(len(count)):
		finalpairlist[y].append(count[y])

	for x in range(len(finalpairlist)):
		finalpairlist[x][0] = tuple(finalpairlist[x][0])
		finalpairlist[x] = tuple(finalpairlist[x])

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
	for o in range(len(kwiclist)):
		kwiclist[o] = tuple(kwiclist[o])

	if listPairs == True:
		kwiclist.append(finalpairlist)
	
	print(kwiclist)
	return kwiclist
