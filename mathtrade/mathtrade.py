n = int(input())

dic = {}
visited = {}

for i in range(n):
    a, b, c = input().strip().split(" ")
    dic[b] = c
    visited[b] = False
    visited[c] = False
final_ans = 0
for k in visited:
    if not visited[k]:
        ans = 1
        curr = k
        visited[curr] = True
        while curr in dic and not visited[dic[curr]]:
            ans += 1
            curr = dic[curr]
            visited[curr] = True
        if curr in dic and visited[dic[curr]]:
            final_ans = max(ans, final_ans)

if final_ans == 0:
    print("No trades possible")
else:
    print(final_ans)
