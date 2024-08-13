n, k = map(int, input().split(" "))
arr = []

tmp = [*map(int, input().split(" "))]

dic = {0: 0, 1: 1, 2: 2, 5: 5, 6: 9, 8: 8, 9: 6}
dic2 = {}

for i in range(len(tmp)):
    num = tmp[i]
    arr.append(num)
    if num in dic2:
        dic2[num] = -1 # signify more than 1, free to use
    else:
        dic2[num] = i
    flag = True
    for char in str(num):
        if char not in ["0", "1", "2", "5", "6", "8", "9"]:
            flag = False
            break
    if flag:
        new = 0
        num2 = num
        while num2 > 0:
            curr = num2 % 10
            new = new * 10 + dic[curr]
            num2 //= 10
        if new != num:
            arr.append(new)
            if new in dic2:
                dic2[new] = -1
            else:
                dic2[new] = i

arr = sorted(arr)
l = 0
r = len(arr) - 1
while l < r:
    if arr[l] + arr[r] == k and (dic2[arr[l]] < 0 or dic2[arr[r]] < 0 or dic2[arr[l]] != dic2[arr[r]]):
        print("YES")
        exit()
    elif arr[l] + arr[r] > k:
        r -= 1
    else:
        l += 1

print("NO")
