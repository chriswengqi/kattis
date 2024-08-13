s = input()

while s.strip() != "0":
    a, b, c, d, e = map(float, s.split())
    print(((abs(a - c)) ** e + (abs(b - d)) ** e) ** (1 / e))
    s = input()