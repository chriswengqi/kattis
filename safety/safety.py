tc = int(input())

def solve(x):
    pref = ["Case #{}:".format(x)]
    inp = [*map(int, input().split(" "))]
    n = inp[0]
    arr = inp[1:]
    total_votes = sum(arr) * 2
    ## percentage needed to stay safe
    non_safe = len([*filter(lambda x: x < total_votes / n, arr)])
    safety = (sum(arr) + sum([*filter(lambda x: x < total_votes / n, arr)])) / non_safe
    ans = []
    for num in arr:
        if num >= total_votes / n:
            ans.append(0)
        else:
            ans.append((safety - num))
    ans = [*map(lambda x: x * 100 / sum(ans), ans)]
    pref.extend(ans)
    print(" ".join(map(str, pref)))



for i in range(1, tc + 1):
    solve(i)