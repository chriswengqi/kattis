import heapq
import sys

min_heap = []
max_heap = []

for line in sys.stdin:
    line = line.strip()
    if line == "#":
        if len(min_heap) == len(max_heap):
            print(heapq.heappop(min_heap))
        else:
            print(-heapq.heappop(max_heap))

    else:
        x = int(line)
        if len(max_heap) == 0 or x <= -max_heap[0]:
            heapq.heappush(max_heap, -x)
        else:
            heapq.heappush(min_heap, x)

    while len(max_heap) > len(min_heap) + 1:
        curr = heapq.heappop(max_heap)
        heapq.heappush(min_heap, -curr)

    while len(min_heap) > len(max_heap):
        curr = heapq.heappop(min_heap)
        heapq.heappush(max_heap, -curr)
