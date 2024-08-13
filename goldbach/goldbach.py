def primes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]


ps = primes(32000)
s = set(ps)

for _ in range(int(input())):
    curr = int(input())
    ans = []
    for num in ps:
        if num * 2 > curr:
            break
        if curr - num in s:
            ans.append((num, curr - num))
    print(f"{curr} has {len(ans)} representation(s)")
    for a, b in ans:
        print(f"{a}+{b}")
    print("")
