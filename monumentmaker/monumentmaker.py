n, d, w = map(int, input().split())

arr = []
for i in range(n):
    curr = input().strip()
    if i % 2 == 1:
        curr = curr[::-1]
    curr = curr.replace(" ", "")
    arr.append(curr)

arr = "".join(arr).split(".")

lines = 0
curr = w
for word in arr:
    s = len(word)
    if curr + s + 1 > w:
        lines += 1
        curr = s
    else:
        curr += s + 1

print(lines)