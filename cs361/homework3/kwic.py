import os
import eventspec

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
        line = ""
        lines = []
        lastChar1 = None
        lastChar2 = None
        breakChars = map(chr, xrange(ord('a'),ord('z')+1))
        for c in string:
            if (c == " ") and (lastChar1 == ".") and (lastChar2 in breakChars):
                lines.append(line)
                line = ""
            line += c
            lastChar2 = lastChar1
            lastChar1 = c
        lines.append(line)
        return lines

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

#pair function for the class
def classPair(string):
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

def sortIndex(string):
	return sorted(string, key = lambda l: (map(lambda w:w.lower(), l[0]),l[1]))

#sorting pairs
def sortPairs(pairs):
	return map(lambda wp: (wp, pairs[wp]), sorted(filter(lambda wp: pairs[wp] > 1, pairs.keys())))

#Flattening
def flatten(string):
	return [l for subList in string for l in subList]

#filter out the ignore words.
def filterIgnoreWords(string, ignoreWords):
	return filter(lambda l: not ignorable(l[0][0], ignoreWords), string)

#The kwic functions
def kwic(string,ignoreWords=[], listPairs=False, periodsToBreaks=False):
    lines = splitBreaks(string, periodsToBreaks)
    splitLines = sentenceSplit(lines)
    pairs = pair(splitLines, listPairs)
    shiftedLines = shiftList(splitLines)
    flattenedLines = flatten(shiftedLines)
    filteredLines = filterIgnoreWords(flattenedLines, ignoreWords)
    sortedLines = sortList(filteredLines, listPairs, pairs)
    return sortedLines

#The kwic class
class Kwic:
	def __init__(self, ignoreWords=[], periodsToBreaks=False):
		self.ignoreWords = ignoreWords
		self.periodsToBreaks = periodsToBreaks
		self.string = ""
		self.es = eventspec.EventSpec("kwic.fsm")

	def addText(self,string):
		self.es.event("callAddText")
		self.string = self.string + string
		self.es.event("textAdded")

	def index(self):
		self.es.event("callIndex")
		lines = splitBreaks(self.string, self.periodsToBreaks)
		splitLines = sentenceSplit(lines)
		shiftedLines = shiftList(splitLines)
		flattenedLines = flatten(shiftedLines)
		filteredLines = filterIgnoreWords(flattenedLines, self.ignoreWords)
		sortedLines = sortIndex(filteredLines)
		self.es.event("returnIndex")
		return sortedLines

	def listPairs(self):
		self.es.event("callListPairs")
		lines = splitBreaks(self.string, self.periodsToBreaks)
		splitLines = sentenceSplit(lines)
		pairs = classPair(splitLines)
		sortedPairs = sortPairs(pairs)
		self.es.event("returnListPairs")
		return sortedPairs

	def reset(self):
		self.es.event("callReset")
		self.string = ""
		self.es.reset()
		self.es.event("resetString")

	def printStatus(self):
		print self.string
		print self.ignoreWords
		print self.periodsToBreaks
		self.es.printLog()

	



	
