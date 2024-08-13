import sys


def gcd(a, b):
    if b > a:
        a, b = b, a
    if a % b == 0:
        return b
    else:
        return gcd(a % b, b)


for line in sys.stdin:
    line = line.strip()
    arr = list(map(lambda x: int(x), line.split(" ")))

    if len(arr) == 1:
        print(arr[0])
    else:
        curr = arr[0] * arr[1] // gcd(arr[0], arr[1])
        for i in range(2, len(arr)):
            curr = curr * arr[i] // gcd(arr[i], curr)
        print(curr)
