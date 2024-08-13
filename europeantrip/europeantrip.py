from math import sqrt

x1, x2 = map(int, input().split())
y1, y2 = map(int, input().split())
z1, z2 = map(int, input().split())

dxy = sqrt((x1 - y1) ** 2 + (x2 - y2) ** 2)
dyz = sqrt((y1 - z1) ** 2 + (y2 - z2) ** 2)
dxz = sqrt((x1 - z1) ** 2 + (x2 - z2) ** 2)