r, s, p = map(int, input().split(" "))

grid = []
for i in range(r):
    x = [*input().strip()]
    grid.append(x)
start = (0, 0)
max_count = 0
for i in range(r - p + 1):
    for j in range(s - p + 1):
        count = 0
        for k in range(i + 1, i + p - 1):
            for l in range(j + 1, j + p - 1):
                if grid[k][l] == "*":
                    count += 1
        if count > max_count:
            max_count = count
            start = (i, j)

x, y = start
grid[x][y] = grid[x + p - 1][y + p - 1] = grid[x][y + p - 1] = grid[x + p - 1][y] = "+"

for i in range(x + 1, x + p - 1):
    grid[i][y] = grid[i][y + p - 1] = "|"
for j in range(y + 1, y + p - 1):
    grid[x][j] = grid[x + p - 1][j] = "-"

print(max_count)
for row in grid:
    print("".join(row))
