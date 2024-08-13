n = int(input())
arr = [*map(int, input().split())]
ans = 0
prev = arr[-1]
for i in range(n - 1, -1, -1):
    ans += min(prev, arr[i])
    prev = min(prev, arr[i])
print(ans)