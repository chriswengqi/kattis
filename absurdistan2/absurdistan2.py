from math import comb

n = int(input())

if n <= 3:
    print(1)
else:
    denom = (n - 1) ** n
    numer = 0
    for i in range(2, n // 2 + 1):
        curr = comb(n, i) * ((i - 1) ** i) * ((n - i - 1) ** (n - i))
        if i == n - i:
            curr //= 2
        numer += curr
    print (1 - numer/denom) 
