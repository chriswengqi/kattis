tc = int(input())

def solve():
    n, k = map(int, input().split())
    arr = []
    for _ in range(k):
        arr.append(input().strip())
    curr = arr[0]
    for i in range(1, k):
        j = 0
        while j <= n and arr[i][: j + 1] == curr[- j - 1:]:
            print(arr[i][:j + 1], curr[-j-1:])
            j += 1
        curr += arr[i][j:]
        print(curr)
    print(curr)
        


for _ in range(tc):
    solve()