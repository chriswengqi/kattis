from math import pi
n = input()
while True:
    a,b,c= map(float,n.split())
    if a == 0 and b == 0 and c == 0:
        break
    print(a*a*pi, c/b*4*a*a)
    n = input()