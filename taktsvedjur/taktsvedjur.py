n = int(input())

arr = []
for _ in range(n):
    arr.append(int(input()))
mul = 1
ans = 0
for i in range(n):
    if arr[i] > 0:
        if i > 0 and arr[i - 1] > 0:
            mul = min(8, mul * 2)
        ans += arr[i] * mul
    else:
        mul = max(mul // 2, 1)
    print(ans)

print(ans)