from collections import deque

def solve():
    dic = {}
    n = int(input())

    adj = {}

    for _ in range(n):
        arr = input().strip().split(" ")
        if len(arr) == 2:
            dic[int(arr[0])] = arr[1]
        else:
            a, b, c, d = map(int, arr)
            if b not in adj:
                adj[b] = []
            if c not in adj:
                adj[c] = []
            if d not in adj:
                adj[d] = []
            adj[b].append(a)
            adj[c].append(a)
            adj[d].append(a)

    dp = {1: 1}
    def dfs(u):
        if u not in dp:
            ttl = 0
            for v in adj[u]:
                ttl += dfs(v)
            dp[u] = ttl
        return dp[u]
    
    ans = 0
    for k, v in dic.items():
        if v == "favourably":
            ans += dfs(k)

    print(ans)

TC = int(input())


for i in range(TC):
    solve()
