n, m = map(int, input().split())

while n != 0 or m != 0:
    for _ in range(n):
        s = [*input().strip()]
        s.sort(key = lambda x: x.lower())
        print("".join(s))
    print("")
    n, m = map(int, input().split())
    