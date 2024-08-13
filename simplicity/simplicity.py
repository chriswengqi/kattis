s = input()
dic = {}
for char in s:
    if char not in dic:
        dic[char] = 0
    dic[char] += 1
ans = sorted(dic.items(), key=lambda x: x[1], reverse=True)
output = 0
while len(ans) > 2:
    output += ans[-1][1]
    ans.pop()
print(output)
