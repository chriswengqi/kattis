from functools import cmp_to_key

n, m = map(int, input().split(" "))
arr1 = [*map(int, input().split(" "))]
arr2 = [*map(int, input().split(" "))]
gears = []
for i in range(n):
    for j in range(m):
        gears.append((arr1[i], arr2[j]))


def compare(c1, c2):
    if c1[0] * c2[1] == c1[1] * c2[0]:
        return c1[0] - c2[0]
    return c1[0] * c2[1] - c1[1] * c2[0]


gears = sorted(gears, key=cmp_to_key(compare))
for x, y in gears:
    print(f"({x},{y})")
