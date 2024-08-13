from math import comb

tc = int(input())

for _ in range(tc):
    n, v1, v2, w = map(int, input().split())a
    m = n - v1 - v2
    t = (n + 2) // 2 - v1
    prob = 0
    for i in range(max(0, t), m + 1):
        prob += comb(m, i) / pow(2, m)
    if prob * 100 > w:
        print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
    elif prob == 0:
        print("RECOUNT!")
    else:
        print("PATIENCE, EVERYONE!") 