n, c, b = map(lambda x: int(x), input().split(" "))

arr = list(map(lambda x: int(x), input().split(" ")))
dic = set(arr)
ans = ["0"] * n

if c % 2 == 1:
    ans[0] = "1"
    c -= 1
c = c // 2
skip = False

for i in range(1, n):
    if i + 1 not in dic and c > 0 and not skip:
        ans[i] = "1"
        skip = True
        c -= 1
    else:
        skip = False

print("".join(ans))
