import sys

for line in sys.stdin:
    n = int(line.strip())
    if n == 0:
        break
    curr = 0
    arr = []
    n -= 1
    while n > 0:
        if n & 1:
            arr.append(pow(3, curr))
        n >>= 1
        curr += 1
    s = ", ".join(map(str, arr))
    if s == "":
        print("{ }")
    else:
        print(f"{{ {s} }}")
