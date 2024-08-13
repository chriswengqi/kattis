n = int(input())
arr = []
for _ in range(n):
    a, b, c = input().split()
    b = int(b)
    c = int(c)
    arr.append((a, b, c))
arr.sort(key=lambda x: (-x[1] * x[2], x[0]))
print(arr[0][0])