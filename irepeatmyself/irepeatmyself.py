n = int(input())

for _ in range(n):
    s = input().strip()
    n = len(s)
    for i in range(1, n + 1):
        if n % i == 0:
            can = True
            for j in range(0, n, i):
                if s[j:j + i] != s[:i]:
                    can = False
                    break
            if can:
                print(i)
                break