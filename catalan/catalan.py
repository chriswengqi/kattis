n = int(input())
arr = [0] * 5001
arr[0] = 1

for i in range(1, 5001):
    arr[i] = arr[i - 1] * (4 * i + 2) // (i + 2)

for i in range(n):
    x = int(input())
    print(arr[x - 1])
