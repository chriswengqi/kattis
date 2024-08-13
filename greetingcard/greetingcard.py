n = int(input())

s = set()

directions = [
    (2018, 0),
    (-2018, 0),
    (0, 2018),
    (0, -2018),
    (1680, 1118),
    (-1680, 1118),
    (1680, -1118),
    (-1680, -1118),
    (1118, 1680),
    (-1118, 1680),
    (1118, -1680),
    (-1118, -1680),
]
ans = 0
for i in range(n):
    x, y = map(int, input().split(" "))
    for dx, dy in directions:
        if (x + dx, y + dy) in s:
            ans += 1

    s.add((x, y))

print(ans)
