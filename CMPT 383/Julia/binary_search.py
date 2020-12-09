import numpy as np
import timeit

# def binary_search (arr, begin, end, target):
#     if begin <= end:
#         mid = int(begin + (end - begin) / 2)
#         if arr[mid] == target:
#             return mid
#         elif arr[mid] > target:
#             return binary_search(arr, begin, mid-1, target)
#         else:
#             return binary_search(arr, mid+1, end, target)
#     else:
#         return -1

def binary_search(l, value, low = 0, high = -1):
    if not l: return -1
    if(high == -1): high = len(l)-1
    if low >= high:
        if l[low] == value: return low
        else: return -1
    mid = (low+high)//2
    if l[mid] > value: return binary_search(l, value, low, mid-1)
    elif l[mid] < value: return binary_search(l, value, mid+1, high)
    else: return mid

def main():
    start = timeit.default_timer()
    arr = np.arange(0, 1000000, 2).tolist()
    for target in range(0,1000000):
        # binary_search(arr, 0, len(arr)-1, target)
        binary_search(arr, target, 0, len(arr)-1)

    
    stop = timeit.default_timer()
    print('Time: ', stop - start)

if __name__ == "__main__":
    main()

