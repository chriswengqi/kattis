n=int(input())
arr = [*map(int,input().split())]
arr2=sorted(arr)
ans = 0
for i in range(n):
    if arr[i] != arr2[i]:
        ans += 1
print(ans)