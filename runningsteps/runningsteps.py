from math import comb

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    ans = 0
    for i in range(1, b // 2 + 1):
        j = b - 2 * i
        if i >= j and i % 2 == 0 and j % 2 == 0:
            print(i, j)
            ## j is min
            ans += comb(i + 1, j)
    ## print(a, ans)
