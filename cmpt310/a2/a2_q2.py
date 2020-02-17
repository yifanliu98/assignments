# a2_q2.py

def check_teams(graph, csp_sol):
    for i in range(len(csp_sol)):
        for j in range(i+1, len(csp_sol)):
            if csp_sol[i] == csp_sol[j]:
                if graph[i].count(j):
                    return False
    return True
