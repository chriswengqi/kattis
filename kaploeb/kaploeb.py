l, k, s = map(int, input().split())
dic = {}
for i in range(l):
    a, b = input().split()
    a = int(a)
    hh, ss = map(int, b.split("."))
    if a not in dic:
        dic[a] = [0, 0]
    dic[a][0] += 1
    dic[a][1] += hh * 60 + ss
ans = []
for key, v in dic.items():
    if v[0] == k:
        ans.append((key, v[1]))
ans.sort(key=lambda x: (x[1], x[0]))
for k, _ in ans:
    print(k)
