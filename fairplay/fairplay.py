n = int(input())
dic = {}

l, r = 0, 0
arr = []
for _ in range(n):
    a, b = map(int, input().split())
    if (a, b) not in dic:
        dic[(a, b)] = 0
    dic[(a, b)] += 1
    arr.append((a, b))
    l += a
    r += b
if n % 2 != 0 or l % (n // 2) != 0 or r % (n // 2) != 0:
    print("impossible")
    exit()
avg_l = l // (n // 2)
avg_r = r // (n // 2)
for i in range(n // 2):
    a, b = arr[i]
    if (avg_l - a, avg_r - b) in dic and dic[(avg_l - a, avg_r - b)] > 0:
        dic[(avg_l - a, avg_r - b)] -= 1
    else:
        print("impossible")
        exit()
print("possible")


