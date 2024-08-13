import fractions

n = int(input())
for _ in range(n):
    a, b, c = input().split()
    a = int(a)
    b = int(b)
    c = float(c)

    f = fractions.Fraction.from_float(c)

    ff = f.limit_denominator(max_denominator=b)

    print(a, f"{ff.numerator}/{ff.denominator}")