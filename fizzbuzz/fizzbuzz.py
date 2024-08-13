n, k = map(int, input().split())

ans = []
for i in range(1, k + 1):
    if i % 3 == 0 and i % 5 == 0:
        ans.append("fizzbuzz")
    elif i % 3 == 0:
        ans.append("fizz")
    elif i % 5 == 0:
        ans.append("buzz")
    else:
        ans.append(str(i))
scores = []
for i in range(n):
    ttl = 0
    arr = input().strip().split()
    for j in range(len(arr)):
        if arr[j] == ans[j]:
            ttl += 1
    scores.append(ttl)
mx = -1
ans = -1
for i in range(len(scores)):
    if scores[i] > mx:
        mx = scores[i]
        ans = i + 1
print(ans)

