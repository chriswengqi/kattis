n = int(input())

for i in range(n):
    arr = input().split(",")
    ans = 0
    power = 1
    for i in range(len(arr) - 1, -1, -1):
        if arr[i] == "":
            pass
        else:
            ans += power * int(arr[i])
        power *= 60
    print(ans)
