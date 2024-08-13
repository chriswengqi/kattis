from collections import deque


def solve():
    visited = [[[0] * c for i in range(r)] for j in range(l)]
    directions = [[1, 0, 0], [-1, 0, 0], [0, 1, 0], [0, -1, 0], [0, 0, 1], [0, 0, -1]]

    grid = []
    for i in range(l):
        level = []
        for j in range(r):
            level.append(input())
        grid.append(level)
        input()

    start = None

    for i in range(l):
        for j in range(r):
            for k in range(c):
                if grid[i][j][k] == "S":
                    start = (i, j, k)
                    break

    dq = deque([])
    dq.append((0, start))

    found = False

    while len(dq) > 0:
        curr, [x, y, z] = dq.popleft()
        for dx, dy, dz in directions:
            if (
                0 <= x + dx < l
                and 0 <= y + dy < r
                and 0 <= z + dz < c
                and grid[x + dx][y + dy][z + dz] == "E"
            ):
                print(f"Escaped in {curr + 1} minute(s).")
                return
            if (
                0 <= x + dx < l
                and 0 <= y + dy < r
                and 0 <= z + dz < c
                and not visited[x + dx][y + dy][z + dz]
                and grid[x + dx][y + dy][z + dz] == "."
            ):
                dq.append((curr + 1, (x + dx, y + dy, z + dz)))
                visited[x + dx][y + dy][z + dz] = 1

    if not found:
        print("Trapped!")


l, r, c = map(lambda x: int(x), input().split(" "))

while l != 0 and r != 0 and c != 0:
    solve()
    l, r, c = map(lambda x: int(x), input().split(" "))
