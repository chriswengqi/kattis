from math import sin, cos, pi
n = int(input())

for _ in range(n):
    a, b, c, d, e = map(float, input().split())
    t = c / (a * cos(b / 180 * pi))
    y = a * t * sin(b / 180 * pi) - 0.5 * 9.81 * t * t
    if y - d >= 1 and e - y >= 1:
        print("Safe")
    else:
        print("Not Safe")
