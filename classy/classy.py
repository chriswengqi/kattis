from functools import cmp_to_key

TC = int(input())


def sorter(x1, y1):
    x = x1[1]
    y = y1[1]
    x = x.split("-")
    x.reverse()
    y = y.split("-")
    y.reverse()
    while len(x) > len(y):
        y.append("middle")
    while len(x) < len(y):
        x.append("middle")
    for i in range(max(len(x), len(y))):
        if x[i] > y[i]:
            return -1
        elif x[i] < y[i]:
            return 1
    if x1[0] > y1[0]:
        return 1
    elif x1[0] < y1[0]:
        return -1
    else:
        return 0


def solve():
    n = int(input())
    arr = []
    for i in range(n):
        arr.append(list(input().split(" ")))
    arr.sort(key=cmp_to_key(sorter))

    for item in arr:
        print(item[0].strip(":"))
    print("=" * 30)


for i in range(TC):
    solve()
