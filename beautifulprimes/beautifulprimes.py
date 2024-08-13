def solve():
    x = int(input())
    curr = 1
    power = 10
    ans = []
    for _ in range(x):
        if curr * 7 < power and curr * 7 > power // 10:
            curr *= 7
            ans.append("7")
        else:
            curr *= 17
            ans.append("17")
        power *= 10

    print(" ".join(ans))


n = int(input())

for i in range(n):
    solve()
