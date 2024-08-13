from math import log10, floor

n = input().strip()

if len(n) == 1:
    if n == "1":
        print(1)
    elif n == "2":
        print(2)
    else:
        print(3)
else:
    curr = 0
    cnt = 1
    while curr < len(n):
        curr += log10(cnt)
        if floor(curr + 1) == len(n):
            break
        cnt += 1
    print(cnt)
