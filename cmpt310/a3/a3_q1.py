import math
import time
import os
import xlsxwriter

def exactly_one(var):
    n = len(var)
    arr = []
    if n > 2:
        arr = var
        arr.append(0)
    for i in range(n):
        for j in range(i+1, n):
            arr.append(-var[i])
            arr.append(-var[j])
            arr.append(0)
    return arr

def at_most_one(var):
    n = len(var)
    arr = []
    for i in range(n):
        for j in range(i+1, n):
            arr.append(-var[i])
            arr.append(-var[j])
            arr.append(0)
    return arr


def n_choose_2(n):
    if n<2:
        return 0
    elif n==2:
        return 1
    else:
        return n*(n-1)/2

def num_of_constrants(n):
    if n==2:
        return 6
    num = (2*n+2) * n_choose_2(n) + 2*n
    while n > 2:
        n -= 1
        num += (4 * n_choose_2(n))
    return int(num)

def make_queen_sat(N):
    file = open("q1file.txt","w")
    file.write("c N=%d queens problem\n" %N)
    file.write("p cnf "  + str(N*N) + " " + str(num_of_constrants(N)) + "\n")
    # row 
    arr = []
    for i in range(N):
        for j in range(N):
            arr.append(i*N+j+1)
        arr = exactly_one(arr)
        for k in arr:
            if k == 0:
                file.write(str(k) + "\n")
            else:
                file.write(str(k) + " ")
        arr = []
    
    # colume
    arr = []
    for i in range(N):
        for j in range(N):
            arr.append(i+1+N*j)
        arr = exactly_one(arr)
        for k in arr:
            if k == 0:
                file.write(str(k) + "\n")
            else:
                file.write(str(k) + " ")
        arr = []

    # diagonal
    # right top
    arr = []
    for i in range(N-1):
        arr.append(i+1)
        for j in range(1,N-i):
            arr.append(arr[-1]+N+1)
        arr = at_most_one(arr)
        for k in arr:
            if k == 0:
                file.write(str(k) + "\n")
            else:
                file.write(str(k) + " ")
        arr = []

    #left bottome
    arr = []
    for i in range(N-2):
        arr.append((i+1)*N+1)
        for j in range(1,N-i-1):
            arr.append(arr[-1]+N+1)
        arr = at_most_one(arr)
        for k in arr:
            if k == 0:
                file.write(str(k) + "\n")
            else:
                file.write(str(k) + " ")
        arr = []

    #right bottom
    arr = []
    for i in range(N-1):
        arr.append(N+N*i)
        for j in range(1,N-i):
            arr.append(arr[-1]+N-1)
        arr = at_most_one(arr)
        for k in arr:
            if k == 0:
                file.write(str(k) + "\n")
            else:
                file.write(str(k) + " ")
        arr = []

    #left top
    arr = []
    for i in range(N-2):
        arr.append(i+2)
        for j in range(i+1):
            arr.append(arr[-1]+N-1)
        arr = at_most_one(arr)
        for k in arr:
            if k == 0:
                file.write(str(k) + "\n")
            else:
                file.write(str(k) + " ")       
        arr = []
    file.close()

def draw_queen_sat_sol(sol):
    if sol[0] == 'U':
        print("no solution")
        return
    list = [int(x) for x in sol]
    length = len(list)
    if length > 1601:
        print("too big: N must be less than 40")
        return
    n = int(math.sqrt(length-1))
    for i in range(n):
        for j in range(n):
            if list[i*n+j] < 0:
                print('. ', end = "")
            else:
                print('Q ', end = "")
        print("")
    return

# function to get MAX_N and create a EXCEL worksheet
def MAX_N():
    MAX_N = 2
    times = []
    constrants = []
    elapsed_time = 0
    while elapsed_time < 10:
        make_queen_sat(MAX_N)
        start_time = time.time()
        os.system("minisat {} {}" .format("q1file.txt", "out"))
        elapsed_time = time.time() - start_time
        times.append(elapsed_time)
        constrants.append(num_of_constrants(MAX_N))
        MAX_N += 1
    MAX_N -= 2
    print("MAX_N is %d" %MAX_N)

    workbook = xlsxwriter.Workbook('a3_q1.xlsx')
    worksheet = workbook.add_worksheet()
    worksheet.write(0,0, "MAX_N")
    worksheet.write(0,1, "running_time")
    worksheet.write(0,2, "constrants")    
    for i in range(len(times)):
        worksheet.write(i+1,0, str(i+2))
        worksheet.write(i+1,1, str(times[i]))
        worksheet.write(i+1,2, str(constrants[i]))
    workbook.close()
    return

# MAX_N()
