n, m = map(int, input().split())
dic = {}
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if i + j not in dic:
            dic[i + j] = 0
        dic[i + j] += 1
mx = 0
ans = []
for k, v in dic.items():
    if v > mx:
        mx = v
        ans = [k]
    elif v == mx:
        ans.append(k)
ans.sort()
for num in ans:
    print(num)