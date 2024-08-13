binary = ["000", "001", "010", "011", "100", "101", "110", "111"]

n, l, r = map(lambda x: int(x), input().split())
s = input()
s = "0" * r + s + "0" * r

# create pattern
dic = {}
for i in range(8):
    dic[binary[i]] = str(n % 2)
    n = n // 2

for i in range(r):
    arr = []
    for j in range(len(s) - 2):
        arr.append(dic[s[j : j + 3]])
    s = "".join(arr)
    print(s[r - i - 1 : len(s) - r + i + 1])
