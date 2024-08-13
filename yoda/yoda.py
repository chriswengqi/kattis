a = list(map(lambda x: int(x), [*input()]))
b = list(map(lambda x: int(x), [*input()]))

for i in range(min(len(a), len(b))):
    curr = -i - 1
    if b[curr] > a[curr]:
        a[curr] = -1
    elif b[curr] < a[curr]:
        b[curr] = -1

ans1 = 0
ans2 = 0

for elem in a:
    if elem != -1:
        ans1 = ans1 * 10 + int(elem)

for elem in b:
    if elem != -1:
        ans2 = ans2 * 10 + int(elem)

if max(a) == -1:
    print("YODA")
else:
    print(ans1)
if max(b) == -1:
    print("YODA")
else:
    print(ans2)
