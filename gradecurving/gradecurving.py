from math import sqrt, ceil

x, yl, yh = map(int, input().split(" "))

arr = [0] * 10
arr[0] = x

for i in range(1, 10):
    arr[i] = ceil(10 * sqrt(arr[i - 1]))

minn = -1
maxx = -1

for i in range(len(arr)):
    if yl <= arr[i] <= yh and minn == -1:
        minn = i
    if yl <= arr[i] <= yh:
        maxx = i

if yl == 100:
    print("impossible")
elif yh == 100:
    print(minn, "inf")
elif minn == -1 and maxx == -1:
    print("impossible")
else:
    print(minn, maxx)
