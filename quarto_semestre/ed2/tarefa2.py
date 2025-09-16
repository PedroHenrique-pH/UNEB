import pandas as pd
import time
import random

def quicksort_first(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        left = [x for x in arr[1:] if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr[1:] if x > pivot]
        return quicksort_first(left) + middle + quicksort_first(right)


def quicksort_middle(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr)//2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quicksort_middle(left) + middle + quicksort_middle(right)


def shellsort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j-gap] > temp:
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr

if __name__ == "__main__":
    df = pd.read_csv("archive/ai_assistant_usage_student_life.csv")

    arr = df["TotalPrompts"].dropna().tolist()  

    arr1 = arr.copy()
    arr2 = arr.copy()
    arr3 = arr.copy()
    arr4 = arr.copy()

    start = time.time()
    quicksort_first(arr1)
    print("Quicksort (primeiro pivô):", time.time()-start)

    start = time.time()
    quicksort_middle(arr2)
    print("Quicksort (meio pivô):", time.time()-start)

    start = time.time()
    shellsort(arr3)
    print("Shellsort:", time.time()-start)
