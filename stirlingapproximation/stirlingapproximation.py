from math import log, pi, exp

n = int(input())

facs = [0]
for i in range(1, 100001):
    facs.append(facs[i - 1] + log(i))

while n != 0:
    s = facs[n] - (0.5 * log(2 * pi * n) + n * log(n) - n)
    print(round(exp(s), 10))
    n = int(input())