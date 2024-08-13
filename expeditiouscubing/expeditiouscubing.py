eps = 10**-9
a, b, c, d = map(lambda x: int(float(x) * 100 + eps), input().split(" "))
target = int(float(input()) * 100 + eps)

maxx = max(a, b, c, d)
minn = min(a, b, c, d)
total = a + b + c + d
## larger than maxx
if (total - minn) <= target * 3:
    print("infinite") 

## smallest than min
elif (total - maxx) > target * 3:
    print("impossible")

else:
    curr = total - maxx - minn
    x = target * 3 - curr
    remainder = str(x % 100) if x % 100 >= 10 else '0' + str(x % 100)
    print(f"{x // 100}.{remainder}")
                 