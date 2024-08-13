n = int(input())
arr = list(map(lambda x: int(x), input().split(" ")))
dic = {}

for i, num in enumerate(arr):
    if num not in dic:
        dic[num] = [i + 1, i + 1]
    else:
        dic[num] = [dic[num][0], i + 1]

op = sorted(dic.items(), key=lambda x: (x[1][0], -x[1][1]))

l = -1
r = -1
furthest = r

ans = []
for k, v in op:
    print(k, v[0], v[1])
