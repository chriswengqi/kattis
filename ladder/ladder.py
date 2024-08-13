from math import sin,ceil,radians
n, k = map(int,input().split())
print(ceil(n/sin(radians(k))))