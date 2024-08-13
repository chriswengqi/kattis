a, b = input().split()

def gcd(a, b):
    if b > a:
        return gcd(b, a)
    if b == 0:
        return a
    else:
        return gcd(a % b, b)
    
def add(a, b):
    denom = a[1] * b[1] // gcd(a[1], b[1])
    num = a[0] * (denom // a[1]) + b[0] * (denom // b[1])
    return (num // gcd(num, denom), denom // gcd(num, denom))

b = int(b)
left = a[:-b]
right = a[-b:]
GCD = gcd(int(right), pow(10, b) - 1)
left1, left2 = left.split(".")
right = (int(right) // GCD, (pow(10, b) - 1) // GCD * pow(10, len(left2)))
left = (int(left1) * pow(10, len(left2)) + (int(left2) if left2 != "" else 0), pow(10, len(left2)))
print("/".join(map(str, add(left, right))))