#a2_q1.py

import random

def rand_graph(n, p):
    graph = {}
    for i in range(n):
        graph[i] = []
    for i in range(n):
        for j in range(i+1, n):
            if random.random() <= p:
                graph[i].append(j)
                graph[j].append(i)
    return graph
