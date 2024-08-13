n = int(input())
arr = [*map(int, input().split())]
arr.sort()
ans = 0
for i in range(n // 2 + 1):
    ans += arr[i] // 2
for i in range(n // 2 + 1, n):
    ans += arr[i]
print(ans)