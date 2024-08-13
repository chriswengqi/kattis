n, k = map(int, input().split(" "))
arr = [*map(int, input().split(" "))]

pivot = -1
for i in range(len(arr)):
    if arr[i] == k:
        pivot = i
        break
dic = {}
lp = pivot - 1
ans = 0
big, small = 0, 0
while lp >= 0:
    if arr[lp] > k:
        big += 1
    else:
        small += 1
    if big == small:
        ans += 1
    if big - small not in dic:
        dic[big - small] = 0
    dic[big - small] += 1
    lp -= 1

rp = pivot + 1
big, small = 0, 0
while rp < n:
    if arr[rp] > k:
        big += 1
    else:
        small += 1
    if small == big:
        ans += 1
    if small - big in dic:
        ans += dic[small - big]
    rp += 1

print(ans + 1)
