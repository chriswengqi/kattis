n, m = map(int, input().split())

arr = []
for _ in range(n + m - 1):
    arr.append(float(input()))

dp = [[-1] * (m + 5) for _ in range(n + m + 5)]

def dfs(curr, pts):
    if pts == m:
        return 1
    if curr - pts == n:
        return 0
    if curr == n + m - 1:
        return 0
    if dp[curr][pts] == -1:
        dp[curr][pts] = arr[curr] * dfs(curr + 1, pts + 1) + (1 - arr[curr]) * dfs(curr + 1, pts)
    
    return dp[curr][pts]

print(dfs(0, 0)) 


