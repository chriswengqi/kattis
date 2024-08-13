import sys

for line in sys.stdin:
    line = line.strip()
    a, b, c = line.split(" ")
    a = int(a)
    c = int(c)
    if b == "+":
        print((a + c) % 10000)
    elif b == "*":
        print((a * c) % 10000)
    else:
        dic = {}
        dic[a] = 1
        dp = [1, a]
        curr = a
        offset = -1
        cycle = -1
        for i in range(2, c + 1):
            curr *= a
            curr = curr % 10000
            if curr in dic:
                cycle = i - dic[curr]
                offset = dic[curr]
                break
            else:
                dic[curr] = i
                dp.append(curr)
        if cycle != -1:
            print(dp[offset + (c - offset) % cycle])
        else:
            print(curr)
