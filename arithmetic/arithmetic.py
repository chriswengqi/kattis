s = input()


def base8_to_base2(s):
    s = int(s)
    arr = []
    while s > 0:
        arr.append(str(s % 2))
        s = s // 2
    while len(arr) < 3:
        arr.append("0")
    return "".join(arr[::-1])


def base2_to_base16(s):
    dic = "0123456789ABCDEF"
    ans = 0
    power = 1
    for i in range(min(len(s) - 1, 3), -1, -1):
        ans += power * int(s[i])
        power *= 2
    return dic[ans]


arr = []

for char in s:
    arr.append(base8_to_base2(char))

curr = "".join(arr)[::-1]
ans = []
for i in range(0, len(curr) - 1, 4):
    ans.append(base2_to_base16(curr[i : i + 4][::-1]))

while ans[-1] == "0" and len(s) > 1:
    ans.pop()

print("".join(ans[::-1]))
