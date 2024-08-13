n = int(input())
dic = {}
for _ in range(n):
    name, like, date = input().strip().split()
    if date not in dic:
        dic[date] = []
    dic[date].append((name, int(like)))
ans = []
for date, lst in dic.items():
    mx = max(lst, key=lambda x:x[1])
    ans.append(mx[0])
ans.sort()
print(len(ans))
for name in ans:
    print(name)