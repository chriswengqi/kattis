import sys
ttl = 0
dic = {}
for line in sys.stdin:
    line = line.strip()
    ttl += 1
    if line not in dic:
        dic[line] = 0
    dic[line] += 1
ans = sorted(dic.items(), key=lambda x: x[0])
for k, v in ans:
    print(k, v * 100 / ttl)