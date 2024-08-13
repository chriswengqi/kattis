import sys
from math import log10

arr = [1]
for i in range(1, 1000001):
    arr.append(arr[i - 1] + log10(i))

for line in sys.stdin:
    n = int(line)
    print(int(arr[n]))
