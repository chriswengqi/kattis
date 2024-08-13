n = int(input())
arr = [*map(int, input().split(" "))]


def gcd(a, b):
    if b > a:
        a, b = b, a
    if b == 0:
        return a
    if a % b == 0:
        return b
    else:
        return gcd(a % b, b)


for i in range(1, n):
    g = gcd(arr[0], arr[i])
    x = arr[0] // g
    y = arr[i] // g
    print(f"{x}/{y}")
