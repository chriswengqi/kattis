from math import sin, pi
h, v = map(int, input().split())
if v <= 180:
    print("safe")
else:
    if v <= 270:
        print(int(h / sin((v - 180) / 180 * pi + 1e-9)))
    else:
        print(int(h / sin((360 - v) / 180 * pi + 1e-9)))