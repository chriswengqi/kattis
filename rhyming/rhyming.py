s = input().strip()

n = int(input())
rhymes = []
for _ in range(n):
    rhymes.extend([*input().strip().split()])

q = int(input())
for _ in range(q):
    words = [*input().strip().split()]
    found = False
    word = words[-1]
    for i in range(len(word)):
        if word[-1-i:] in rhymes:
            print(word[-1-i:])
            found = True
            break
    if found:
        print("YES")
    else:print("NO")