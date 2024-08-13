k, n = map(int, input().split(" "))

price = 100001
ans = []

for i in range(n):
    name, p, c, t, r = input().strip().split(",")
    p = int(p)
    c = int(c)
    t = int(t)
    r = int(r)

    times = (t * 10080) / (t + r)
    if times * c >= k and p < price:
        ans = [name]
        price = p
    elif times * c >= k and p == price:
        ans.append(name)

if ans:
    for name in ans:
        print(name)
else:
    print("no such mower")
