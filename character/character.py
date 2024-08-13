from math import comb
n = int(input())
ans = 0
for i in range(2, n + 1):
    ans += comb(n, i)
print(ans)
