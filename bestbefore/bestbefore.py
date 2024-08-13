s = input()
d, m, y = map(int, s.split("/"))
valid = True
if d > 31 or d == 0:
    valid = False
if m in [4,6,9,11] and d > 30:
    valid = False
if m == 2 and ((y % 4 == 0 and d > 29) or (y % 4 != 0 and d > 28)):
    valid = False
if m == 0 or m > 12:
    valid = False
if not valid:
    print(f"{s} is illegal")
else:
    if m < 10: m = '0' + str(m)
    if d < 10: d = '0' + str(d)

    print(f"{y % 2000 + 2000}-{d}-{m}")


