from math import log2

n, m, k = map(int, input().split(" "))


def factorial(x):
    ans = 1
    for i in range(2, x + 1):
        ans *= i
    return ans


fns = [
    lambda x: factorial(x),
    lambda x: 2**x,
    lambda x: x**4,
    lambda x: x**3,
    lambda x: x**2,
    lambda x: x * log2(x),
    lambda x: x,
]

if k == 1 and m >= 13:
    print("TLE")
elif k == 2 and m >= 30:
    print("TLE")
elif k == 3 and m >= 178:
    print("TLE")
else:
    curr = fns[k - 1](m)
    if curr <= n:
        print("AC")
    else:
        print("TLE")
