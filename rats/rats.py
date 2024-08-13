n = int(input())

def creeper(check):
    if type(check) != str:
        check = str(check)
    if len(check) < 8:
        return False
    return (check[:4] == "1233" and check[-4:] == "4444" and check[4:-4] == "3" * (len(check) - 8)) or (check[:4] == "5566" and check[-4:] == "7777" and check[4:-4] == "6" * (len(check) - 8))

def solve(a, b, c):
    dic = set()
    for j in range(1, b):
        if c in dic or creeper(c):
            print(a, "R" if c in dic else "C", j)
            return
        dic.add(c)
        c = int("".join(sorted([*str(int(c) + int(str(c)[::-1]))])))
    print(a, "C", b) if creeper(c) else print(a, c)

for i in range(n):
    a, b, c = map(int, input().split())
    solve(a, b, c)
    
