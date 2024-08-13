n = int(input())

ans = 0


def dfs(curr):
    global ans
    if curr > n:
        return
    elif curr == n:
        ans += 1
        return
    else:
        for i in range(1, 4):
            dfs(curr + i)


dfs(0)
print(ans)
