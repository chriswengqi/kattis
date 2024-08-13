# https://oeis.org/A006046 

n = int(input())

def solve(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    if n % 2 == 0:
        return 3 * solve(n // 2)
    else:
        return 2 * solve(n // 2) + solve(n // 2 + 1)
    
print(solve(n))