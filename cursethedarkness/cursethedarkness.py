tc = int(input())

for _ in range(tc):
    x, y = map(float, input().split())
    can = False
    n = int(input())

    for i in range(n):
        dx, dy = map(float, input().split())
        if (x - dx) * (x - dx) + (y - dy) * (y - dy) <= 64:
            can = True

    if can:
        print("light a candle")
    else:
        print("curse the darkness")