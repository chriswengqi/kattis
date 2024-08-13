## TLE solution

import sys
pos = [0] * 10001
for line in sys.stdin:
    arr = list(map(int, line.replace(":", "").split()))
    if arr[0] == 0:
        break
    n = arr[0]
    for i in range(1, len(arr)):
        pos[arr[i]] = i - 1
    invalid = 0
    for i in range(n):
        for d in range(-i, i+1):
            if i + 2 * d >= 0 and i + 2 * d < n:
                invalid = (pos[i + d] > pos[i]) & (pos[i + 2 * d] > pos[i + d])
            if invalid: break
        if invalid: break
    if not invalid:
        print("yes")
    else:
        print("no")
