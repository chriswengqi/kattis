n, m = map(int, input().split())
s = input()
MOD, p, curr = 1e9+7, 0, 0
for i in range(n):
    curr = (curr * 10 + int(s[i])) % m
    p += [0, 1][curr == 0]

def power(curr, pow):
    if pow<2:
        return [1, curr][pow]
    x = (power(curr, pow // 2))
    return (x * x) * [1, curr][pow % 2] % MOD

print([0, power(2, p - 1) % MOD][p == 0 or curr != 0])





    



    