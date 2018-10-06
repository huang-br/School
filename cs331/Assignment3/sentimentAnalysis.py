import sys
import os
import string
import math

trainingSet = list()
testSet = list()
vocab = dict()
vocabList = list()
train_f = list()
test_f = list()

totalGood = 1

def reader(inputFile):
	outputFile = []
	with open(inputFile) as f:
		for line in f:
			temp = line.split('\t')
			outputFile.append(((temp[0].translate(None, string.punctuation)).lower(), int(temp[1].strip('\r\n'))))
					
	return outputFile

def featureize():
	global vocab
	global trainingSet
	global testSet
	global totalGood

	totalWordList = []
	for key in vocab:
		totalWordList.append(key)
	
	totalWordList.sort()
	preprocessedTrain = open('preprocessed_train.txt', 'wb')
	preprocessedTest = open('preprocessed_test.txt', 'wb')
	
	s = ', '
	preprocessedTrain.write(s.join(totalWordList) + ", classlabel\n")
	preprocessedTest.write(s.join(totalWordList) + ", classlabel\n")

	for pair in trainingSet:
		sentence = pair[0].split(' ')
		if '' in sentence:
			sentence.remove('')
		temp = list()
		for word in totalWordList:
			if word in sentence:
				preprocessedTrain.write('1, ')
				temp.append(1)
			else:
				preprocessedTrain.write('0, ')
				temp.append(0)
			vocabList.append(word)

		if(pair[1]):
			totalGood += 1

		preprocessedTrain.write(str(pair[1]) + '\n')
		train_f.append(temp)
		
	preprocessedTrain.close()

	for pair in testSet:
		sentence = pair[0].split(' ')
		if '' in sentence:
			sentence.remove('')
		temp = list()
		for word in totalWordList:
			if word in sentence:
				preprocessedTest.write('1, ')
				temp.append(1)
			else:
				preprocessedTest.write('0, ')
				temp.append(0)
			vocabList.append(word)

		preprocessedTest.write(str(pair[1]) + '\n')
		test_f.append(temp)
	
	preprocessedTest.close()


def makeVocab(sentenceValueTuple):
	global vocab
	for pair in sentenceValueTuple:
		for word in pair[0].split(' '):
			if word not in vocab.keys():
				#[WordCount, GoodCount, BadCount]
				if pair[1] == 1:
					vocab[word] = [1, 1, 0]
				else:
					vocab[word] = [1, 0, 1]
			elif word in vocab.keys():
				if pair[1] == 1:
					vocab[word][0] += 1
					vocab[word][1] += 1
				else:
					vocab[word][0] += 1
					vocab[word][2] += 2

def preProcess(trainingFile, testFile):
	global trainingSet
	global testSet

	trainingSet = reader(trainingFile)
	testSet = reader(testFile)
	makeVocab(trainingSet)
	makeVocab(testSet)

def classify():
	prob = {}
	result = open("results.txt", 'wb')

	for key, val in vocab.iteritems():
		prob[key] = [float(val[1]) / float(val[0]), float(val[1]) / float(val[0]), float(val[2]) / float(val[0]), float(val[2]) / float(val[0])]

	for dataSet in [train_f, train_f]:
		count = 0
		for f in dataSet:
			trueProduct = 1.0
			falseProduct = 1.0
			for i in range(len(f) - 1):
				if f[i]:
					if vocabList[i] in prob.keys():
						trueProduct += prob[vocabList[i]][0]
						falseProduct += prob[vocabList[i]][3]
			
			if trueProduct >= falseProduct:
				if f[-1]:
					count += 1
			else:
				if not f[-1]:
					count += 1

	result.write("Training v Training\n")
	print "Training Correct Percent: ", (float(count) / float(len(dataSet)))
	result.write("Training v Training Percentage: " + str(float(float(count) / float(len(dataSet)))) + '\n')
	print "Data set size: ", len(dataSet)
	result.write("Data set size " + str(len(dataSet)) + '\n')
	print "Number Correct: ", count
	result.write("Number Correct " + str(count) + '\n\n')

	for dataSet in [train_f, test_f]:
		count = 0
		for f in dataSet:
			trueProduct = 1.0
			falseProduct = 1.0
			for i in range(len(f) - 1):
				if f[i]:
					if vocabList[i] in prob.keys():
						trueProduct += prob[vocabList[i]][0]
						falseProduct += prob[vocabList[i]][3]
			
			if trueProduct >= falseProduct:
				if f[-1]:
					count += 1
			else:
				if not f[-1]:
					count += 1

	result.write("Training v Test\n")
	print "Testing Correct Percent: ", (float(count) / float(len(dataSet)))
	result.write("Training v Testing Percentage: " + str(float(float(count) / float(len(dataSet)))) + '\n')
	print "Data set size: ", len(dataSet)
	result.write("Data set size " + str(len(dataSet)) + '\n')
	print "Number Correct: ", count
	result.write("Number Correct " + str(count) + '\n\n')

	result.close()

def main():
	if(len(sys.argv) == 1):
		print "USAGE: python sentimentAnalysis.py <trainingSet.txt> <testSet.txt>\n"

	else:
		train = sys.argv[1]
		test = sys.argv[2]
	
		preProcess(train, test)
		del vocab['']
	
		featureize()
		classify()

if __name__ == "__main__":
	main()

