bs = []
primes = []

def sieve(upperbound):

  _sieve_size = upperbound+1
  bs = [True] * _sieve_size
  bs[0] = bs[1] = False
  for i in range(2, _sieve_size):
    if bs[i]:
      for j in range(i*i, _sieve_size, i):
        bs[j] = False
      primes.append(str(i))
sieve(2000000)
l, h = map(int, input().split())
n = input().strip()
ans = 0
for i in range(l - 1, h):
  if n in primes[i]:
    ans += 1
print(ans)
