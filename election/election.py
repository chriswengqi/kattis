n = int(input())
dic = {}

for i in range(n):
    x = input().strip()
    y = input().strip()
    dic[x] = y

l = int(input())
freq = {}
for i in range(l):
    x = input().strip()
    if x not in freq:
        freq[x] = 0
    freq[x] += 1

ans = list(sorted(freq.items(), key=lambda x: x[1]))
if len([*filter(lambda x: x[1] == ans[-1][1], ans)]) > 1:
    print("tie")
else:
    print(dic[ans[-1][0]])
