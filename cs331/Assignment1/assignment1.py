import os
import sys
import Queue
import collections
import copy

possibleActions = [[2,0],[1,0],[1,1],[0,1],[0,2]] #[Number of chickens, Number of Wolves]

#Node Class
class Node():
	def __init__(self, left, right, parent, depth, action):
		self.left = left
		self.right = right
		self.state = [left, right]
		self.parent = parent
		self.depth = depth
		self.action = action
	
	
#File reader
def readFileState(file):
	state = list()
	with open(file) as f:
		data = f.read()
	splitData = data.split()
	for line in splitData:
		state.append(line.split())
	left = map(lambda x: int(x), state[0][0].split(','))
	right = map(lambda x: int(x), state[1][0].split(','))
	newNode = Node(left, right, 0, 0, 0)
	return newNode

#Checks if the action is valid
def actionCheck(state, action):
	
	if(state[0][2] == 1):
		start = list(state[0])
		end = list(state[1])
	else:
		start = list(state[1])
		end = list(state[0])

	start[0] -= action[0]
	start[1] -= action[1]
	end[0] += action[0]
	end[1] += action[1]

	if((start[0] or start[1]) < 0):
		return False
	elif(((start[0] == 0) or (start[0] >= start[1])) and ((end[0] == 0) or (end[0] >= end[1]))):
		return True
	else:
		return False

#Does the action
def action(gameNode, action):

	gameState = copy.deepcopy(gameNode.state)
	print(action)
	#Boat starts on the left
	if(gameNode.state[0][2] == 1):
		gameState[0][0] -= action[0]
		gameState[0][1] -= action[1]
		gameState[0][2] = 0
		gameState[1][0] += action[0]
		gameState[1][1] += action[1]
		gameState[1][2] = 1
	#Boat starts on the right
	else:
		gameState[0][0] += action[0]
		gameState[0][1] += action[1]
		gameState[0][2] = 1
		gameState[1][0] -= action[0]
		gameState[1][1] -= action[1]
		gameState[1][2] = 0
	
	gameNode.action = action
	print("endState", gameNode.state)
	print("gameState", gameState)
	gameNode.state = gameState
	return gameNode

def expand(gameNode):
	global possibleActions
	successorNodes = list()
	validActions = list(filter(lambda x: actionCheck(gameNode.state, x), possibleActions))
	expandedNodes = list(map(lambda y: action(gameNode, y), validActions))

	print(validActions)

	for successorState in expandedNodes:
		newNode = Node(successorState.left, successorState.right, gameNode, gameNode.depth + 1, successorState.action)
		successorNodes.append(newNode)
		print(newNode.state,newNode.action)
	
	return successorNodes

def DFS(nodes, initialNode, finalNode):
	vistedNodes = {}
	nodes.append(initialNode)
	while(1):
		if(len(nodes) == 0):
			sys.exit("No Solution")
	
		currentNode = nodes.popleft()
	
		if(currentNode == finalNode):
			return currentNode
			
		if(currentNode in vistedNodes and currentNode.depth >= vistedNodes[currentNode.state]):
			continue
		else:
			vistedNodes[currentNode] = currentNode.depth
			map(nodes.append, expand(currentNode))

	






#####MAIN#####
initialNode = readFileState(sys.argv[1])
goalNode = readFileState(sys.argv[2])
mode = sys.argv[3]
outputName = sys.argv[4]


if(mode == "dfs"):
	DFS(collections.deque(), initialNode, goalNode)
	

