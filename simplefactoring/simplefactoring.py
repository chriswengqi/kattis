from math import sqrt

n = int(input())
EPS = 1e-9
for _ in range(n):
    a, b, c = map(int, input().split())
    if b * b - 4 * a * c >= 0:
        val = sqrt(b * b - 4 * a * c)
        if abs(int(val + EPS) - val) < EPS:
            print("YES")
        else:
            print('NO')
    else:
        print("NO")