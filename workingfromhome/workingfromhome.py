from math import ceil

m, p, n = map(lambda x: int(x), input().split(" "))

curr = m
ans = 0

for i in range(n):
    w = int(input())
    if w >= curr:
        ans += 1
    curr = ceil(m + (curr - w) * p / 100)

print(ans)
