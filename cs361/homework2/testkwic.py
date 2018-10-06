import os
#shifts the words. 
def shift(line):
    return [line[i:] + line[:i] for i in xrange(0,len(line))]

#shifts the whole list
def shiftList(lines):
    return [map(lambda x:(x,i), shift(lines[i])) for i in xrange(0,len(lines))]

#removing punctuation.
def cleanWord(word):
    return filter (lambda c: c not in [".",",","?","!",":"], word.lower())

#The ignore works function
def ignorable(word,ignoreWords):
    return cleanWord(word) in map(lambda w: w.lower(), ignoreWords)

#The periods to breaks function
def splitBreaks(string, periodsToBreaks):
    if not periodsToBreaks:
        return string.split("\n")
    else:
        return string.split('. ')

#splitting the sentence into a list of words
def sentenceSplit(string):
	return map(lambda l: l.split(), string)

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

#sorting
def sortList(string, listPairs, pairs):	
    if not listPairs:
	    return sorted(string, key = lambda l: (map(lambda w:w.lower(), l[0]),l[1]))
    else:
        return (sorted(string, key = lambda l: (map(lambda w:w.lower(), l[0]),l[1])),
                map(lambda wp: (wp, pairs[wp]), sorted(filter(lambda wp: pairs[wp] > 1, pairs.keys()))))

#Flattening
def flatten(string):
	return [l for subList in string for l in subList]

#filter out the ignore words.
def filterIgnoreWords(string, ignoreWords):
	return filter(lambda l: not ignorable(l[0][0], ignoreWords), string)

#The kwic functions
def kwic(string,ignoreWords=[], listPairs=False, periodsToBreaks=False):
	choice = raw_input("Do you want to turn on the testing feature? (y/n)")
	if choice == 'y':
		os.system('clear')
    		lines = splitBreaks(string, periodsToBreaks)
		assert(lines)
		print(lines)
    		raw_input('press ENTER to continue...')
		os.system('clear')
    		splitLines = sentenceSplit(lines)
		assert(splitLines)
		print(splitLines)
    		raw_input('press ENTER to continue...')
		os.system('clear')
    		pairs = pair(splitLines, listPairs)
		assert(pairs)
		print(pairs)
   	 	raw_input('press ENTER to continue...')
		os.system('clear')
   	 	shiftedLines = shiftList(splitLines)
		assert(shiftedLines)
		print(shiftedLines)
    		raw_input('press ENTER to continue...')
		os.system('clear')
   	 	flattenedLines = flatten(shiftedLines)
		assert(flattenedLines)
		print(flattenedLines)
    		raw_input('press ENTER to continue...')
		os.system('clear')
   	 	filteredLines = filterIgnoreWords(flattenedLines, ignoreWords)
		assert(filteredLines)
		print(filteredLines)
		raw_input('press ENTER to continue...')
		os.system('clear')
   	 	sortedLines = sortList(filteredLines, listPairs, pairs)
		assert(sortedLines)
		print(sortedLines)
		return sortedLines
	else:
    		lines = splitBreaks(string, periodsToBreaks)
    		splitLines = sentenceSplit(lines)
    		pairs = pair(splitLines, listPairs)
    		shiftedLines = shiftList(splitLines)
    		flattenedLines = flatten(shiftedLines)
    		filteredLines = filterIgnoreWords(flattenedLines, ignoreWords)
    		sortedLines = sortList(filteredLines, listPairs, pairs)
		return sortedLines
