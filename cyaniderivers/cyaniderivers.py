s = input()
arr = []
for i in range(len(s)):
    if s[i] == '1':
        arr.append(i)
ans = 0
for i in range(1, len(arr)):
    diff = arr[i] - arr[i - 1]
    ans = max(ans, diff // 2)
print(ans)