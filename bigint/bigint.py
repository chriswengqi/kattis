a, n = map(int, input().split())

def power(a, n):
    if n == 1:
        return a
    curr = power(a, n >> 1)
    ans = curr * curr
    if n & 1:
        ans *= a
    return ans

ans = 0
for i in range(1, n + 1):
    ans += i * power(a, i)

print(ans)

