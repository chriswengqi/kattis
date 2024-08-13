import sys

for line in sys.stdin:
    line = line.strip()
    k, n = map(lambda x: int(x), line.split(" "))
    dp = [[1] * (k + 1) for _ in range(n)]

    ans = 0

    if k == 0:
        print(100)
        continue

    for i in range(1, n):
        for j in range(k + 1):
            if j == 0:
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1]
            elif j == k:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]

    for i in range(k + 1):
        ans += dp[n - 1][i]

    print(round(ans / pow(k + 1, n) * 100, 10))
