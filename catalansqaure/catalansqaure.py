n = int(input())
arr = [0] * (n + 2)
arr[0] = 1
for i in range(n + 1):
    arr[i + 1] = arr[i] * (4 * i + 2) // (i + 2)
print(arr[n + 1])
