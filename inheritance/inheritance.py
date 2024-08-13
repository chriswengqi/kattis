n = int(input())
ans = []
def dfs(curr):
    if n % curr == 0:
        ans.append(curr)
    if curr > n:
        return
    dfs(curr * 10 + 2)
    dfs(curr * 10 + 4)

dfs(2)
dfs(4)
ans.sort()
for num in ans:
    print(num)