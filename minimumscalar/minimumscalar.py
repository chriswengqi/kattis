tc = int(input())
for i in range(1, tc + 1):
    n = int(input())
    arr = [*map(int, input().split())]
    arr.sort()
    rev = [*map(int, input().split())]
    rev.sort(reverse=True)
    total = 0
    for j in range(n):
        total += arr[j] * rev[j]
    print(f"Case #{i}: {total}")