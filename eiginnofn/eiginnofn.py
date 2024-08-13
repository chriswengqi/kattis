n = int(input())
dic = {}
for _ in range(n):
    s = [*input().split()]
    if len(s) == 1:
        dic[s[0]] = ""
    else:
        dic[s[0]] = s[1]

m = int(input())
for _ in range(m):
    s = input().strip()
    if s not in dic:
        print("Neibb")
    elif s in dic and dic[s] == "":
        print("Jebb")
    else:
        print(f"Neibb en {s} {dic[s]} er heima")