a,b=int(input()),int(input())

front = b - a if b >= a else b + 360 - a
back = b - a if a >= b else b - 360 - a

if front <= abs(back):
    print(front)
else:
    print(back)
