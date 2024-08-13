n = int(input())
c = "welcome to code jam"



for i in range(1, n + 1):
    s = input().strip()
    curr = 0
    dp = [[-1] * (len(c) + 1) for _ in range(len(s) + 1)]
    def dfs(idx, curr):
        if curr == len(c):
            return 1
        if idx == len(s):
            return 0
        if dp[idx][curr] != -1:
            return dp[idx][curr]
        ans = dfs(idx + 1, curr)
        if s[idx] == c[curr]:
            ans += dfs(idx + 1, curr + 1)
        dp[idx][curr] = ans
        return ans
    ans = dfs(0, 0) % 10000
    output = "0" * (4 - len(str(ans))) + str(ans)
    print(f"Case #{i}: {output}")
