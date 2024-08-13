import sys


def factorial(n):
    ans = 1
    for i in range(2, n + 1):
        ans *= i
    return ans


for line in sys.stdin:
    dic = {}
    line = line.strip()
    for char in line:
        if char not in dic:
            dic[char] = 0
        dic[char] += 1
    ans = factorial(len(line))
    for k, v in dic.items():
        ans = ans // factorial(v)
    print(ans)
