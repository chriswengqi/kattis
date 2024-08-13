n = int(input())
bin = input().split(" ")
dic = {}
for i in range(len(bin)):
    dic[bin[n - i - 1]] = n - i - 1

s = input()
start = 0
arr = []
for i in range(len(s)):
    if s[start : i + 1] in dic:
        arr.append(dic[s[start : i + 1]])
        start = i + 1
arr.reverse()
ans = 0
for i in range(len(arr)):
    ans += arr[i] * (n**i)
print(ans)
