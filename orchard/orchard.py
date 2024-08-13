a, b, c, d, e = map(int, input().split())

dp = {}

def dfs(a, b, c, d, e):
    if a + b + c + d == 0:
        return 1
    if e == 0:
        return 0
    if (a, b, c, d, e) in dp:
        return dp[(a, b, c, d, e)]
    ans = 0
    x = 0
    if a > 0:
        ans += dfs(a - 1, b, c, d, e) / 6
    else:
        x += 1
    if b > 0:
        ans += dfs(a, b - 1, c, d, e) / 6
    else: x += 1
    if c > 0:
        ans += dfs(a, b, c - 1, d, e) / 6
    else: x += 1
    if d > 0:
        ans += dfs(a, b, c, d - 1, e) / 6
    else: x += 1

    ans += dfs(a, b, c, d, e - 1) / 6
    curr = max(a, b, c, d)
    if a == curr:
        ans += dfs(a - 1, b, c, d, e) / 6
    elif b == curr:
        ans += dfs(a, b - 1, c, d, e) / 6
    elif c == curr:
        ans += dfs(a, b, c - 1, d, e) / 6
    else:
        ans += dfs(a, b, c, d - 1, e) / 6
    dp[(a, b, c, d, e)] = 6 / (6 - x) * ans
    return dp[(a, b, c, d, e)]

print(dfs(a, b, c, d, e))

        
