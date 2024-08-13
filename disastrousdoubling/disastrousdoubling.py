n = int(input())
arr = list(map(lambda x: int(x), input().split(" ")))

ans = 1
for elem in arr:
    ans *= 2
    ans -= elem

    if ans < 0:
        print("error")
        exit()

print(ans % 1000000007)
