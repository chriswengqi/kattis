l, k, s = map(int, input().split())

dic = {}
for i in range(l):
    a, b = input().split()
    a = int(a)
    b = float(b)
    if a not in dic:
        dic[a] = [0, 0]
    dic[a][0] += 1
    dic[a][1] += b
ans = []
for k, v in dic.items():
    if v[0] == k:
        ans.append((k, v[1]))
ans.sort(key=lambda x: x[1])
for k, _ in ans:
    print(k)
