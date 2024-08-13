n = int(input())

arr = [0, 1, 3, 6, 10, 15, 21, 28, 36, 45]

def f(n):
    curr = 10
    ans = 0
    while curr <= n:
        ans += (n // curr) * (45 * curr // 10)
        curr *= 10
    return ans


for _ in range(n):
    a, b = map(int, input().split())
    print(f(b))