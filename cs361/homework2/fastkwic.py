#shifts the words. 
def shift(line):
    return [line[i:] + line[:i] for i in xrange(0,len(line))]

#removing punctuation.
def cleanWord(word):
    return filter (lambda c: c not in [".",",","?","!",":"], word.lower())

#The ignore works function
def ignorable(word,ignoreWords):
    return cleanWord(word) in map(lambda w: w.lower(), ignoreWords)

def splitBreaks(string, periodsToBreaks):
	if not periodsToBreaks:
		return string.split("\n")
	else:
		return string.split('. ')

#pair function
def pair(string, listPairs):
	if not listPairs:
		return
	else:
		pairs = {}
		for l in string:
            		seen = set([])
            		for wu1 in l:
                		wc1 = cleanWord(wu1)
                		if len(wc1) == 0:
					continue
                		for wu2 in l:
                    			wc2 = cleanWord(wu2)
                    			if wc1 < wc2:
                        			if (wc1,wc2) in seen:
                            				continue
                        			seen.add((wc1,wc2))
                        			if (wc1, wc2) in pairs:
                            				pairs[(wc1,wc2)] += 1
                        			else:
                            				pairs[(wc1,wc2)] = 1
		return pairs

#The kwic functions
def kwic(string,ignoreWords=[], listPairs=False, periodsToBreaks=False):
    lines = splitBreaks(string, periodsToBreaks) 
    splitLines = map(lambda l: l.split(), lines)
    pairs = pair(splitLines, listPairs) 
    shiftedLines = (map(lambda x:(x,i), shift(splitLines[i])) for i in xrange(0,len(splitLines))) #used generator format instead of list comprehention here
    flattenedLines = (l for subList in shiftedLines for l in subList) #also changed to a generator
    filteredLines = filter(lambda l: not ignorable(l[0][0], ignoreWords), flattenedLines)
    if not listPairs:
	    return sorted(filteredLines, key = lambda l: (map(lambda w:w.lower, l[0]),l[1]))
    else:
        return (sorted(filteredLines, key = lambda l: (map(lambda w:w.lower(), l[0]),l[1])),
                map(lambda wp: (wp, pairs[wp]), sorted(filter(lambda wp: pairs[wp] > 1, pairs.keys()))))
