n, m = map(int, input().split())
t = n // 3
min_a = t + (n % 3 >= 2)
min_b = t
if m >= min_a + min_b + 2:
    print("Unnar")
else:
    print("Arnar")