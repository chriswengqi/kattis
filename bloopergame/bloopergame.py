import heapq
from math import ceil

n, l, p = input().strip().split(" ")
n = int(n)
l = int(l)
p = float(p)
dic = {}
pq = []
for i in range(n):
    s = int(input())
    heapq.heappush(pq, 1 / s)

while l > 0:
    curr = ceil(l / n)
    x = heapq.heappop(pq)
    x = pow(x, pow(p, curr))
    l -= curr
    heapq.heappush(pq, x)


ans = 1
while len(pq) > 0:
    ans *= heapq.heappop(pq)
print(ans)
