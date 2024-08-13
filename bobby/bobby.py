from math import comb
tc = int(input())

for _ in range(tc):
    r, s, x, y, w = map(int, input().split())
    prob = (s - r + 1) / s
    total_prob = 0
    for i in range(x, y + 1):
        total_prob += comb(y, i) * pow(prob, i) * pow(1 - prob, y - i)

    odds = 1 / total_prob if total_prob != 0 else 10**9
    if odds < w:
        print("yes")
    else:
        print("no")


