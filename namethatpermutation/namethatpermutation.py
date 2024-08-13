import sys


def factorial(n):
    ans = 1
    for i in range(2, n + 1):
        ans *= i
    return ans


while True:
    x = sys.stdin.readline()
    if not x:
        break
    n, k = map(lambda x: int(x), x.split(" "))
    lst = [i for i in range(1, n + 1)]
    ans = []
    num = k
    for i in range(n - 1, 0, -1):
        fac = factorial(i)
        output = num // fac
        ans.append(lst[output])
        lst.pop(output)
        num = num % fac
    ans.append(lst[0])

    print(" ".join(map(lambda x: str(x), ans)))
