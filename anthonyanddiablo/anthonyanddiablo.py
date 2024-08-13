from math import pi, sqrt
a, b = map(float,input().split())
r = sqrt(a/pi)
if 2*pi*r <= b:
    print("Diablo is happy!")
else:
    print("Need more materials!")