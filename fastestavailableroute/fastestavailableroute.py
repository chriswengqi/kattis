from collections import deque

h, w, s = map(lambda x: int(x), input().split(" "))

start = None
end = None
grid = []
for i in range(h):
    curr = input()
    if "@" in curr:
        start = (i, curr.index("@"))
    if "$" in curr:
        end = (i, curr.index("$"))
    grid.append([*curr])

directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

q = deque([])
q.append((start, 0))

found = False

while len(q) > 0:
    (x, y), dist = q.popleft()
    for dx, dy in directions:
        if 0 <= x + dx < h and 0 <= y + dy < w:
            if grid[x + dx][y + dy] == "$":
                print(f"Your destination will arrive in {(dist + 1) * s} meters")
                found = True
            if grid[x + dx][y + dy] == ".":
                q.append(((x + dx, y + dy), dist + 1))
                grid[x + dx][y + dy] = "X"

    if found:
        break
