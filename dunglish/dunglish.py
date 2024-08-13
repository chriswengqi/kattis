n = int(input())
arr = [*input().strip().split()]
m = int(input())
dic = {}
for _ in range(m):
    a, b, c = input().strip().split()
    if a not in dic:
        dic[a] = [[], []]
    if c == "correct":
        dic[a][0].append(b)
    else:
        dic[a][1].append(b)

ans = []
valids = 1
total = 1
valid = True
for word in arr:
    u, v = dic[word]
    if len(u) + len(v) == 1:
        if len(u) == 1:
            ans.append(u[0])
        else:
            ans.append(v[0])
            valid = False
    else:
        valids *= len(u)
        total *= (len(u) + len(v))

if len(ans) == len(arr):
    print(" ".join(ans))
    print(["incorrect", "correct"][valid])
else:
    print(valids, "correct")
    print(total - valids, "incorrect")

            
