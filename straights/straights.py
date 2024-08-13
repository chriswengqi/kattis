import heapq

n = int(input())
arr = [*map(int, input().strip().split(" "))]

pq = []
dic = {}
for num in arr:
    if num not in dic:
        dic[num] = 0
    dic[num] += 1
for k, v in dic.items():
    heapq.heappush(pq, (k, v))

ans = 0

while len(pq) > 0:
    temp = []
    k, v = heapq.heappop(pq)
    if v > 1:
        temp.append((k, v - 1))
    curr = k
    while len(pq) > 0 and pq[0][0] == curr + 1:
        k, v = heapq.heappop(pq)
        curr = k
        if v > 1:
            temp.append((k, v - 1))
    ans += 1
    for k, v in temp:
        heapq.heappush(pq, (k, v))

print(ans)
