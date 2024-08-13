def gcd(a, b):
    if b > a:
        return gcd(b, a)
    if b == 0:
        return a
    else:
        return gcd(a % b, b)

def add(f1, f2):
    n1, d1 = f1
    n2, d2 = f2
    denom = d1 * d2 // gcd(d1, d2)
    n1 *= denom // d1
    n2 *= denom // d2
    sm = n1 + n2
    return (sm // gcd(sm, denom), denom // gcd(sm, denom))

n = int(input())
arr = [*map(int, input().split())]

def f(x):
    if x == n - 1:
        return (arr[n - 1], 1)
    a, b = f(x + 1)
    return add((arr[x], 1), (b, a))

ans = f(0)
print(f"{ans[0]}/{ans[1]}") 