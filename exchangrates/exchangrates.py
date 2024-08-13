n = int(input())

while n != 0:
    arr = []
    for i in range(n):
        arr.append(float(input()))

    dp = [[-1] * 2 for _ in range(n + 1)]
    
    def dfs(curr, par, ttl):
        if curr == n:
            if par == 0:
                return ttl
            else:
                return 0
        
        if dp[curr][par] != -1:
            return dp[curr][par]
        
        ## exchange or dont exchange
        if par == 0:
            dp[curr][par] = max(dfs(curr + 1, par, ttl), dfs(curr + 1, 1 - par, int(ttl / arr[curr]) - int(0.03 * ttl / arr[curr])))
        else:
            dp[curr][par] =  max(dfs(curr + 1, par, ttl), dfs(curr + 1, 1 - par, int(ttl * arr[curr]) - int(0.03 * ttl * arr[curr])))
        return dp[curr][par]
    ans = int(dfs(0, 0, 100000))
    print(f"{ans // 100}.{'0' if ans % 100 < 10 else ''}{ans % 100}")


    n = int(input())