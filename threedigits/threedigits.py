n = int(input())
curr = 1
twos = 0
fives = 0
for i in range(1, n + 1):
    curr *= i
    while curr % 10 == 0:
        curr = curr // 10
    while curr % 2 == 0:
        curr = curr // 2
        twos += 1
    while curr % 5 == 0:
        curr = curr // 5
        fives += 1
    curr = curr % 1000000
twos -= fives
for i in range(twos):
    curr *= 2
    curr %= 1000
curr = curr % 1000
print(curr if n <= 6 else '0' * (3 - len(str(curr))) + str(curr))