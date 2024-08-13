import sys


def binary_search(n):
    left = 0
    right = pow(10, 167)

    while left < right - 1:
        mid = (left + right) // 2
        if mid * mid * mid == n:
            return mid
        elif mid * mid * mid > n:
            right = mid
        else:
            left = mid
    if abs(left * left * left - n) < abs((left + 1) * (left + 1) * (left + 1) - n):
        return left
    else:
        return left + 1


for line in sys.stdin:
    line = line.strip()
    line = int(line)
    print(binary_search(line))
