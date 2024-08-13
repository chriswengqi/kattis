from math import perm, comb
n, m, k = map(int, input().split())

ans = 0
for i in range(k, min(n, m) + 1):
    ans += comb(n, i) * perm(n, i)
print(ans / pow(n, m))

