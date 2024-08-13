arr = [*map(int, input().split())]
k = int(input())

def count_bits(n):
    ttl = 0
    while n > 0:
        ttl += n % 2
        n //= 2
    return ttl

total = 0

for i in range(1, 1024):
    if count_bits(i) == k:
        ans = 1
        for j in range(10):
            if i & (1 << j) != 0:
                ans *= arr[j]

        total += ans
print(total)
