n = int(input())
dic = {}

for i in range(n):
    arr = list(input().strip().split(" "))
    if arr[0] not in dic:
        dic[arr[0]] = {}
    for i in range(1, len(arr)):
        if arr[i] not in dic[arr[0]]:
            dic[arr[0]][arr[i]] = 0
        dic[arr[0]][arr[i]] += 1

new_dic = {}
for _, v in dic.items():
    for k, v2 in v.items():
        if k not in new_dic:
            new_dic[k] = [0, 0]
        new_dic[k][0] += 1
        new_dic[k][1] += v2

filtered = list(filter(lambda x: x[1][0] == len(dic), new_dic.items()))
ans = sorted(filtered, key=lambda x: (-x[1][1], x[0]))

if not ans:
    print("ALL CLEAR")
else:
    for k, v in ans:
        print(k)
