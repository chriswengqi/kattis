from math import gcd

tc = int(input())

def solve(x):
    arr = [*map(int, input().split(" "))]
    GCD = abs(arr[1] - arr[2])
    for i in range(3, len(arr)):
        GCD = gcd(GCD, abs(arr[i] - arr[i - 1]))
    ans = ["Case #{}: ".format(x)]
    if arr[1] % GCD == 0:
        ans.append(0)
    else:
        ans.append(GCD - arr[1] % GCD)
    print("".join(map(str, ans)))



for i in range(1, tc + 1):
    solve(i)