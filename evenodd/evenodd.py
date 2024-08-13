l, r = map(int, input().split(" "))
MOD = 1000000007
def F(x):
    if x == 1:
        return 0
    elif x % 2 == 0:
        return (x // 2 + 2 * F(x // 2) + x - 2) % MOD
    else:
        return (F(x - 1) + f(x)) % MOD


def f(x):
    it = 0
    while x > 1:
        if x % 2 == 0:
            x = x // 2
        else:
            x += 1
        it += 1
    return it

if l == 1:
    print(F(r) % MOD)
else:
    print((F(r) - F(l - 1)) % MOD)