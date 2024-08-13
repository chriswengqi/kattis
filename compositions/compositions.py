for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    dic = {}
    def dfs(n):
        if n == 0:
            return 1
        if n not in dic:
            ans = 0
            for i in range(1, n + 1):
                if i % d == c:
                    continue
                ans += dfs(n - i)
            dic[n] = ans
        return dic[n]
    print(a, dfs(b))