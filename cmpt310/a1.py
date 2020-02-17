# a1.py

from search import *
import random
import time
# ...

# Part 1  ---------------------------------------------------------------------

def make_rand_8puzzle(): 
    arr=[0,1,2,3,4,5,6,7,8]
    puzzle = EightPuzzle(tuple(arr))
    while True:
        random.shuffle(arr)
        if puzzle.check_solvability(tuple(arr)):
            break
    puzzle.initial = tuple(arr)
    return puzzle 

def make_rand_Ypuzzle():  
    arr=[0,1,2,3,4,5,6,7,8]
    puzzle = YPuzzle(tuple(arr))
    while True:
        random.shuffle(arr)
        if puzzle.check_solvability(tuple(arr)):
            break
    puzzle.initial = tuple(arr)
    return puzzle 
    
def display (state):
    for i in range (0,len(state)):
        if state[i] == 0: print('*', end='')
        else: print(state[i], end='')
        if i%3 == 2: print('\0')
    print('\0')        

def display_Y (state):
    for i in range (0,len(state)):
        if i==1 or i==8: print(' ',end='')
        if state[i] == 0: print('*', end='')
        else: print(state[i], end='')
        if i%3 == 1: print('\0')
    print('\0')         

# Part 2 ----------------------------------------------------------------------------

def manhattan(node):
	state = node.state
	index_goal = {0:[2,2], 1:[0,0], 2:[0,1], 3:[0,2], 4:[1,0], 5:[1,1], 6:[1,2], 7:[2,0], 8:[2,1]}
	index_state = {}
	index = [[0,0], [0,1], [0,2], [1,0], [1,1], [1,2], [2,0], [2,1], [2,2]]
	x, y = 0, 0
        
	for i in range(len(state)):
		index_state[state[i]] = index[i]
	
	mhd = 0
	for i in range(8):
		for j in range(2):
			mhd = abs(index_goal[i][j] - index_state[i][j]) + mhd
        
	return mhd


def astar_search(problem, h=None):
    """A* search is best-first graph search with f(n) = g(n)+h(n).
    You need to specify the h function when you call astar_search, or
    else in your Problem subclass."""
    h = memoize(h or problem.h, 'h')
    return best_first_graph_search(problem, lambda n: n.path_cost + h(n))

def best_first_graph_search(problem, f):
    """Search the nodes with the lowest f scores first.
    You specify the function f(node) that you want to minimize; for example,
    if f is a heuristic estimate to the goal, then we have greedy best
    first search; if f is node.depth then we have breadth-first search.
    There is a subtlety: the line "f = memoize(f, 'f')" means that the f
    values will be cached on the nodes as they are computed. So after doing
    a best first search you can examine the f values of the path returned."""
    f = memoize(f, 'f')
    node = Node(problem.initial)
    frontier = PriorityQueue('min', f)
    frontier.append(node)
    explored = set()
    count=0
    while frontier:
        node = frontier.pop()
        count+=1
        if problem.goal_test(node.state):
            return node, count
        explored.add(node.state)
        for child in node.expand(problem):
            if child.state not in explored and child not in frontier:
                frontier.append(child)
            elif child in frontier:
                if f(child) < frontier[child]:
                    del frontier[child]
                    frontier.append(child)
    return None, None

def max_heuristic(node):
    puzzle = EightPuzzle(node.state)
    return max(puzzle.h(node), manhattan(node))
    
def part2():
    print('8-puzzle')
    for i in range(1,11):
        puzzle = make_rand_8puzzle()
        print(f'({i})')
        display(puzzle.initial)
    
        print('Misplaced Tile Heuristic')
        start_time = time.time()
        node, num = astar_search(puzzle, puzzle.h)
        elapsed_time = time.time() - start_time
        print(f'elapsed time (in seconds): {elapsed_time}')
        print(f'length of solution: {node.path_cost}')
        print(f'nodes removed: {num}\n')

        print('Manhattan Heuristic')
        start_time = time.time()
        node, num = astar_search(puzzle, manhattan)
        elapsed_time = time.time() - start_time
        print(f'elapsed time (in seconds): {elapsed_time}')
        print(f'length of solution: {node.path_cost}')
        print(f'nodes removed: {num}\n')

        print('Max Heuristic')
        start_time = time.time()
        node, num = astar_search(puzzle, max_heuristic)
        elapsed_time = time.time() - start_time
        print(f'elapsed time (in seconds): {elapsed_time}')
        print(f'length of solution: {node.path_cost}')
        print(f'nodes removed: {num}\n')

# Part3 --------------------------------------------------------------------------------------

def max_heuristic_Y(node):
    puzzle = YPuzzle(node.state)
    return max(puzzle.h(node), manhattan_Y(node))


class YPuzzle(Problem):

    def __init__(self, initial, goal=(1, 2, 3, 4, 5, 6, 7, 8, 0)):
        """ Define goal state and initialize a problem """

        self.goal = goal
        Problem.__init__(self, initial, goal)
    
    def find_blank_square(self, state):
        """Return the index of the blank square in a given state"""

        return state.index(0)
    
    def actions(self, state):
        """ Return the actions that can be executed in the given state.
        The result would be a list, since there are only four possible actions
        in any given state of the environment """
        
        possible_actions = ['UP', 'DOWN', 'LEFT', 'RIGHT']       
        index_blank_square = self.find_blank_square(state)
        if index_blank_square < 2:
            return ['DOWN']
        if index_blank_square == 8:
            return ['UP']
        if index_blank_square % 3 == 2:
            possible_actions.remove('LEFT')
        if index_blank_square % 3 == 1:
            possible_actions.remove('RIGHT')
        if index_blank_square == 3:
            possible_actions.remove('UP')
        if index_blank_square == 5 or index_blank_square == 7:
            possible_actions.remove('DOWN')

        return possible_actions

    def result(self, state, action):
        """ Given state and action, return a new state that is the result of the action.
        Action is assumed to be a valid action in the state """

        # blank is the index of the blank square
        blank = self.find_blank_square(state)
        new_state = list(state)
        
        if blank == 0: 
            delta = {'DOWN':2}
        elif blank == 2:
            delta = {'UP':-2, 'DOWN':3, 'LEFT':-1, 'RIGHT':1}
        elif blank == 8:
            delta = {'UP':-2}
        elif blank == 6:
            delta = {'UP':-2, 'DOWN':2, 'LEFT':-1, 'RIGHT':1}
        else:
            delta = {'UP':-3, 'DOWN':3, 'LEFT':-1, 'RIGHT':1}
        
        neighbor = blank + delta[action]
        new_state[blank], new_state[neighbor] = new_state[neighbor], new_state[blank]

        return tuple(new_state)

    def goal_test(self, state):
        """ Given a state, return True if state is a goal state or False, otherwise """

        return state == self.goal

    def check_solvability(self, state):
        """ Checks if the given state is solvable """
        if state[8] != 0 and state[8] != 7:
            return False
        if state[8] == 7:
            if state[0] == 0 and state[1] == 2 and state[2] == 1: pass
            elif state[0] == 1 and state[1] == 0 and state[4] == 2: pass
            elif state[0] == 1 and state[1] == 2: pass 
            else:
                return False
        else:
            if state[0] == 1 and state[1] == 2 and state[6] == 7: pass
            else:
                return False

        inversion = 0
        for i in range(2,8):
            for j in range(i+1, 8):
                if (state[i] > state[j]) and state[i] != 0 and state[j]!= 0:
                    inversion += 1
        
        return inversion % 2 == 0
    
    def h(self, node):
        """ Return the heuristic value for a given state. Default heuristic function used is 
        h(n) = number of misplaced tiles """

        return sum(s != g for (s, g) in zip(node.state, self.goal))

def mhd_Y(start, end):
    """ Given two index start and end, calculate the distance from start to end"""
    
    if start == end:
        return 0
    if start > end:
        return mhd_Y(end, start)
    if end == 1:
        return 4
    elif end == 8:
        return 1 + mhd_Y(start,6)
    elif end-start == 3:
        return 1
    elif end-start and (start+end)%3 != 0:
        return 1       
    elif end == 4:
        return 1 + mhd_Y(start,3)
    elif end == 3:
        return 2
    else:
        return 1 + mhd_Y(start,end-3)

def manhattan_Y(node):
    index = [8, 0, 1, 2, 3, 4, 5, 6, 7]
    mhd = 0
    for i in range(len(node.state)):
        mhd += mhd_Y(i, index[node.state[i]])
            
    return mhd
            
def part3():
    print('Y-puzzle')
    for i in range(1,11):
        puzzle = make_rand_Ypuzzle()
        print(f'({i})')
        display_Y(puzzle.initial)
    
        print('Misplaced Tile Heuristic')
        start_time = time.time()
        node, num = astar_search(puzzle, puzzle.h)
        elapsed_time = time.time() - start_time
        print(f'elapsed time (in seconds): {elapsed_time}')
        print(f'length of solution: {node.path_cost}')
        print(f'nodes removed: {num}\n')

        print('Manhattan Heuristic')
        start_time = time.time()
        node, num = astar_search(puzzle, manhattan_Y)
        elapsed_time = time.time() - start_time
        print(f'elapsed time (in seconds): {elapsed_time}')
        print(f'length of solution: {node.path_cost}')
        print(f'nodes removed: {num}\n')

        print('Max Heuristic')
        start_time = time.time()
        node, num = astar_search(puzzle, max_heuristic_Y)
        elapsed_time = time.time() - start_time
        print(f'elapsed time (in seconds): {elapsed_time}')
        print(f'length of solution: {node.path_cost}')
        print(f'nodes removed: {num}\n')      

      
            
part2()
part3()

