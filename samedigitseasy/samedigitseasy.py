a, b = map(int, input().split())

def digit_preserve(a, b, c):
    dat = [0] * 10
    while a > 0:
        dat[a % 10] += 1
        a //= 10
    while b > 0:
        dat[b % 10] += 1
        b //= 10
    while c > 0:
        dat[c % 10] -= 1
        c //= 10
    return min(dat) == 0 and max(dat) == 0

ans = []
for i in range(a, b + 1):
    for j in range(i, b + 1):
        prod = i * j
        if digit_preserve(i, j, prod):
            ans.append((i, j, prod))

print(f"{len(ans)} digit-preserving pair(s)")
for a, b, c in ans:
    print(f"x = {a}, y = {b}, xy = {c}")
