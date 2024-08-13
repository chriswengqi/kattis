k, n = map(int, input().split(" "))

arr = []
registered = [0] * n
for i in range(n):
    arr.append(int(input()))

flag = True
while k > 0 and flag:
    for i in range(len(arr)):
        if registered[i] < arr[i]:
            registered[i] += 1
            k -= 1
        if k == 0:
            flag = False
            break
    if sum(registered) == sum(arr):
        break

for num in registered:
    print(num)
