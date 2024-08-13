n = int(input())
arr = []
for _ in range(n):
    s, t = input().split()
    t = int(t)
    arr.append((t, s))
arr.sort(reverse = True)
ans = 0
for i in range(0, n, 2):
    if i % 2 == 0:
        ans += arr[i][0]
print(ans)

