n = int(input())

def gcd(a, b):
    a = abs(a)
    b = abs(b)
    if b > a:
        return gcd(b, a)

    if b == 0:
        return a
    else:
        return gcd(b, a % b)

for _ in range(n):
    a, b, c, d, e = input().split()
    a = int(a)
    b = int(b)
    d = int(d)
    e = int(e)
    if c in "*/":
        if c == '/':
            d, e = e, d
        num = a * d
        denom = b * e
        if denom < 0:
            denom *= -1
            num *= -1
        if num != 0:
            print(num // gcd(num, denom), '/', denom // gcd(num, denom))
        else:
            print(0, '/', 1)
    else:
        if b < 0: 
            b = abs(b)
            a *= -1
        if e < 0:
            e = abs(e)
            d *= -1
        denom = b * e // gcd(b, e)
        a *= (denom // b)
        d *= (denom // e)
        numer = a + d if c == '+' else a - d
        if numer == 0:
            print(0, '/', 1)
        else:
            print(numer // gcd(numer, denom), '/', denom // gcd(numer,denom))

        
    
