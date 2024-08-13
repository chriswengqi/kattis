import math
arr = [[0,0]] * 9
for i in range(3):
    curr = [*map(int, input().split())]
    for j in range(3):
        arr[curr[j] - 1] = [i, j]
ans = 0
for i in range(1, 9):
    ans += math.sqrt((arr[i][0] - arr[i - 1][0])**2+(arr[i][1]-arr[i - 1][1])**2)
print(ans)
        