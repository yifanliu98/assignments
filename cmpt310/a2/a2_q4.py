# a2_q4.py

from a2_q1 import rand_graph
from csp import CSP
from csp import min_conflicts_value
from csp import random
from csp import MapColoringCSP
import time


def min_conflicts(csp, max_steps=100000):
    """Solve a CSP by stochastic hillclimbing on the number of conflicts."""
    # Generate a complete assignment for all variables (probably with conflicts)
    csp.current = current = {}
    nassign = 0
    for var in csp.variables:
        val = min_conflicts_value(csp, var, current)
        csp.assign(var, val, current)
        nassign += 1
    # Now repeatedly choose a random conflicted variable and change it
    for i in range(max_steps):
        conflicted = csp.conflicted_vars(current)
        if not conflicted:
            return current, nassign
        var = random.choice(conflicted)
        val = min_conflicts_value(csp, var, current)
        csp.assign(var, val, current)
        nassign += 1
    return None, nassign


def q4():
    graphs = [rand_graph(100, 0.1), rand_graph(100, 0.2), rand_graph(100, 0.3), rand_graph(100, 0.4), rand_graph(100, 0.5)]
    for i in range(5):
        g = graphs[i] 
        print('graph ',i)
        print(g)
        start_time = time.time()
        teams = 100 
        while teams > 0:
            doms = range(0,teams)
            csp = MapColoringCSP(doms, g)
            result,nassign = min_conflicts(csp)
            elapsed_time = time.time() - start_time
            if (result == None):
                print('Smallest number of teams is: ', teams)
                print('Running time (in seconds): ',elapsed_time)
                break
            print('Number of teams is: ', teams)
            print('Running time (in seconds): ',elapsed_time)
            print('Number of assigned and unassigned: ', nassign)
            teams -= 1

def run_q4():
    q4()


run_q4()
