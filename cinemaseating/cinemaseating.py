r, c = map(int, input().split())
grid = [[0] * c for _ in range(r)]
n = int(input())
for _ in range(n):
    x, y = map(int, input().split())
    grid[x - 1][y - 1] = 1
ans = [0] * 9
for i in range(r):
    for j in range(c):
        if grid[i][j] == 1:
            ttl = 0
            for dx in range(max(0, i-1), min(i+2, r)):
                for dy in range(max(0, j-1), min(j+2, c)):
                    ttl += grid[dx][dy]
            ans[ttl - 1] += 1

print(" ".join(map(str, ans)))