import math

a, b, c = map(float, input().split())
lhs = a ** 4 + b** 4 + c ** 4
rhs = a ** 2 + b ** 2 + c ** 2
l,r = 0,1000000
while l + 10e-6 < r:
    mid = (l + r) / 2
    left = 3 * (lhs + mid ** 4)
    right = (rhs + mid** 2)**2
    if left < right:
        l = mid
    else:
        r = mid
print(l)
print(l * l / 4 * math.sqrt(3) if l > 10e-6 and l < 1000000 - 10e-6 else -1)
