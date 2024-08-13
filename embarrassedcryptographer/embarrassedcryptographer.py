def primes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]


ps = primes(1000001)

n, k = map(int, input().split())
while n != 0 or k != 0:
    flag = False
    for i in range(len(ps)):
        if ps[i] >= k:
            flag = True
            print("GOOD")
            break
        elif n % ps[i] == 0:
            flag = True
            print(f"BAD {ps[i]}")
            break
    if not flag:
        print("GOOD")


    n, k = map(int, input().split())