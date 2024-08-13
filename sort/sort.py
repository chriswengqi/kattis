n, k = map(int, input().split(" "))
arr = [*map(int, input().split(" "))]
dic = {}

for i in range(n):
    if arr[i] not in dic:
        dic[arr[i]] = [0, i]
    dic[arr[i]][0] += 1

lst = sorted(dic.items(), key=lambda x: (-x[1][0], x[1][1]))
new_arr = []

for k, v in lst:
    curr = [k] * v[0]
    new_arr.extend(curr)

print(" ".join(map(str, new_arr)))
