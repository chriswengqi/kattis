n = int(input())
s = input()

digits = 1
ptr = 0
flag = False

for i in range(1, n):
    if i == 10:
        digits = 2
    if i == 100:
        digits = 3
    this = s[ptr : ptr + digits]
    if int(this) != i:
        print(i)
        flag = True
        break
    ptr += digits

if not flag:
    print(n)
