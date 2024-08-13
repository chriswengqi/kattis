a, b, c = map(lambda x: int(x), input().split())

ops = ["+", "-", "*", "//"]

ans = 1000000001

for i in range(len(ops)):
    for j in range(len(ops)):
        if ops[i] == "//" and (b == 0 or a % b != 0):
            continue
        tmp = eval(f"{a}{ops[i]}{b}")
        if ops[j] == "//" and (c == 0 or tmp % c != 0):
            continue
        curr = eval(f"{tmp}{ops[j]}{c}")
        if curr >= 0:
            ans = min(curr, ans)

print(ans)
