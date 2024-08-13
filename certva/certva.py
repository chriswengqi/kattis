arr = [0] * 6
arr[0],arr[3] = map(int, input().split())
arr[1],arr[4] = map(int, input().split())
arr[2],arr[5] = map(int, input().split())
dic_x,dic_y={},{}
for i in range(3):
    if arr[i] in dic_x:
        dic_x.pop(arr[i])
    else:
        dic_x[arr[i]] = 1
for i in range(3,6):
    if arr[i] in dic_y:
        dic_y.pop(arr[i])
    else:
        dic_y[arr[i]] = 1
ans = [0,0]
for k, v in dic_x.items():
    ans[0] = k
for k, v in dic_y.items():
    ans[1] = k
print(" ".join(map(str, ans)))    