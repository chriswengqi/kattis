s,t = map(int, input().strip().split("/"))

s -= (32 * t)
s *= 5
t *= 9

def gcd(a, b):
    if b > a:
        return gcd(b, a)
    if b == 0:
        return a
    else:
        return gcd(a % b, b)
print(f"{s//gcd(abs(s), abs(t))}/{t//gcd(abs(s),abs(t))}")