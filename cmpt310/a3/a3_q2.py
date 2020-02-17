import os
import random
import time
from a3_q1 import *

def rand_graph(n, p):
    graph = {}
    for i in range(1,n+1):
        graph[i] = []
    for i in range(1,n+1):
        for j in range(i+1, n+1):
            if random.random() <= p:
                graph[i].append(j)
                graph[j].append(i)
    return graph

def friend_constrants(graph,k):
    num = 0
    for i in range(1,len(graph)+1):
        length = 1
        for j in graph[i]:
            if j > i:
                length += 1
        num += n_choose_2(length)
    return int(num)*k

def team_constrants(n,k):
    return (n_choose_2(k)+1)*n

def find_min_teams(graph):
    start_time = time.time()
    for i in range(1,len(graph)+1):
        print("k = %d" %i)
        make_ice_breaker_sat(graph,i)
        os.system("minisat {} {}" .format("q2file.txt", "out"))
        file = open("out","r")
        sol = ""
        for word in file:
            sol += word
        file.close()
        if sol == "UNSAT\n":
            continue
        else:
            for word in sol.split():
                if word != "SAT" and word != 0:
                    if int(word) > 0:
                        elapsed_time = time.time() - start_time
                        return i, elapsed_time


def make_ice_breaker_sat(graph,k):
    n = len(graph)
    constrants = friend_constrants(graph,k) + team_constrants(n,k)
    file = open("q2file.txt","w")
    file.write("c N=%d Ice Breaker problem\n" %n)
    file.write("p cnf "  + str(n*k) + " " + str(int(constrants)) + "\n")

    for team in range(k):
        for i in range(1,n+1):
            friends = [i+team*n]
            for j in graph[i]:
                if j > i:
                    friends.append(j+team*n)
            friends = at_most_one(friends)
            for j in friends:
                if j == 0:
                    file.write(str(j) + "\n")
                else:
                    file.write(str(j) + " ")
            friends = []
    
    for i in range(1,n+1):
        teams = [i]
        for j in range(k-1):
            teams.append(teams[-1]+n)
        teams = exactly_one(teams)
        for j in teams:
            if j == 0:
                file.write(str(j) + "\n")
            else:
                file.write(str(j) + " ")
        teams = []
    file.close()

    return

teams = []
times = []
for i in range(1,10):
    team, t = find_min_teams(rand_graph(11,i*0.1))
    teams.append(team)
    times.append(t)

for i in teams:
    print(i)

for i in times:
    print(i)
