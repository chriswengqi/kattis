arr = [*map(int, input().split())]
n = len(arr)
for i in range(n - 1):
    for j in range(n - 1):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
            print(" ".join(map(str, arr)))