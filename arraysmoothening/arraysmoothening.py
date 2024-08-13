n, k = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))
dic = {}

for num in arr:
    if num not in dic:
        dic[num] = 0
    dic[num] += 1

tmp = list(sorted(dic.values(), reverse=True))

curr = tmp[0]
cnt = [0] * (len(tmp) + 1)
total = 0
for i in range(1, len(tmp)):
    if tmp[i - 1] == tmp[i]:
        cnt[i] = cnt[i - 1]
        continue
    cnt[i] = cnt[i - 1] + (tmp[i - 1] - tmp[i]) * i
print(tmp, cnt)
