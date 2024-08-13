n, k = map(int, input().split())
s = set()
arr = []
for i in range(n):
    a, b, c = map(int, input().split())
    arr.append((a, b, c, i))
arr.sort(key = lambda x: x[0])
for i in range(k):
    s.add(arr[-i-1][3])
arr.sort(key = lambda x: x[1])
for i in range(k):
    s.add(arr[-i-1][3])
arr.sort(key = lambda x: x[2])
for i in range(k):
    s.add(arr[-i-1][3])
print(len(s))