n = int(input())
arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append([a, b])
curr = 0
for i in range(1, n):
    curr_attacks = (arr[i][0] + arr[curr][1] - 1) // arr[curr][1]
    his_attacks = (arr[curr][0] + arr[i][1] - 1) // arr[i][1]
    if curr_attacks < his_attacks:
        curr = i
print(i + 1)