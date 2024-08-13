n = int(input())
names = []
adj = [set() for _ in range(1000)]
dic = {}
for _ in range(n):
    s = input().strip().split()
    if s[0] not in dic:
        dic[s[0]] = len(names)
        names.append(s[0])

    for i in range(1, len(s)):
        if s[i] not in dic:
            dic[s[i]] = len(names)
            names.append(s[i])
        if dic[s[i]] not in adj[dic[s[0]]]:
            adj[dic[s[0]]].add(dic[s[i]])
        if dic[s[0]] not in adj[dic[s[i]]]:
            adj[dic[s[i]]].add(dic[s[0]])

src, dst = input().split()
if src not in dic or dst not in dic:
    print("no route found")
    exit(0)
stack = []
found = False
def dfs(u, prev):
    if u == dic[dst]:
        print(" ".join(map(lambda x: names[x], stack)))
        exit(0)
    for v in adj[u]:
        if v != prev:
            stack.append(v)
            dfs(v, u)
            stack.pop()
stack.append(dic[src])
dfs(dic[src], -1)
print("no route found")