import sys

for line in sys.stdin:
    a, b, c, d, e = line.strip().split()
    t1, t2 = map(int, d.split(":"))
    u1, u2 = map(int, e.split(":"))
    ttl = (u1 - t1) * 60 + (u2 - t2)
    print(a,b,c,ttl // 60, "hours", ttl % 60, "minutes")