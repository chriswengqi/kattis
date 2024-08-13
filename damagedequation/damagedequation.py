a, b, c, d = input().split(" ")

operators = ["*", "+", "-", "//"]

ans = []
for i in range(4):
    for j in range(4):
        if (i == 3 or j == 3) and (b == "0" or d == "0"):
            continue
        lhs = a + operators[i] + b
        rhs = c + operators[j] + d
        if eval(lhs) == eval(rhs):
            ans.append(
                f"{a} {operators[i]} {b} = {c} {operators[j]} {d}".replace("//", "/")
            )


ans.sort()
if len(ans) == 0:
    print("problems ahead")
else:
    for elem in ans:
        print(elem)
