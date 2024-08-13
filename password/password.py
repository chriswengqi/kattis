n = int(input())
arr = []
ans = 0
for i in range(n):
    a, b = input().split()
    b = float(b)
    arr.append((b, a))
arr.sort(reverse=True)
for i in range(n):
    ans += (i + 1) * arr[i][0]
print(ans)