dic = {0: 6}
curr = 6
for i in range(1, 101):
    curr *= i
    while curr % 10 == 0:
        curr = curr // 10
    dic[i] = curr % 10

n = int(input())
while n != 0:
    if n == 1:
        print(1)
    else:
        print(dic[n % 100])

    n = int(input())
