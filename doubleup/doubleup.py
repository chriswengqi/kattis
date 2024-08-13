import heapq

n = int(input())
dic = {}
arr = [*map(int, input().split())]
pq = []
for num in arr:
    heapq.heappush(pq, num)
while len(pq) > 1:
    x = heapq.heappop(pq)
    y = heapq.heappop(pq)
    while len(pq) > 0 and x != y:
        x = y
        y = heapq.heappop(pq)
    if x == y:
        heapq.heappush(pq, x + y)
    if len(pq) == 0:
        print(y)
        exit()

print(pq[0])
    