tc = int(input())

for _ in range(tc):
    n, m = map(int, input().split())
    arr = []
    for i in range(n):
        arr.append(input())
    ans = []
    for i in range(m):
        ttl = 0
        for j in range(n):
            ttl += (arr[j][i] == '1')
        ans.append([0, 1][ttl > (n // 2)])
    print("".join(map(str, ans)))