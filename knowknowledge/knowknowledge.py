n = int(input())
s = set([*map(int, input().split())])
t = [*map(int, input().split())]
for num in t:
    s.remove(num)
print(list(s)[0])