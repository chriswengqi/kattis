s = input().strip()
while s != ".":
    n = len(s)
    found = False
    for i in range(1, n // 2 + 1):
        if n % i != 0:
            continue
        curr = s[:i]
        valid = True
        for j in range(0, n - i + 1, i):
            if s[j:j+i] != curr:
                valid = False
                break
        if valid:
            print(n // i)
            found = True
            break
    if not found:
        print(1)


    s = input().strip()