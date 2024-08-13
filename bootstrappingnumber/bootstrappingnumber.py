n = int(input())

x = 1
while True:
    if x**x > n:
        x -= 1
        break
    elif x**x == n:
        break
    x += 1
div = 10
for i in range(8):
    left = 0
    right = 9
    while left <= right:
        mid = (left + right) // 2
        curr = x + mid / div
        if pow(curr, curr) > n:
            right = mid - 1
        else:
            left = mid + 1
    x += (left - 1) / div
    div *= 10


print(x)
