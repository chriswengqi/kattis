s = input()
n = int(input())

nxt = []
dic = {}

for i in range(n):
    x = input()
    if x[0] == s[-1]:
        nxt.append(x)
    if x[0] not in dic:
        dic[x[0]] = []
    dic[x[0]].append(x)

if nxt == []:
    print("?")
else:
    flag = False
    for animal in nxt:
        if animal[-1] not in dic or (
            animal[-1] in dic
            and len(dic[animal[-1]]) == 1
            and dic[animal[-1]][0] == animal
        ):
            print(f"{animal}!")
            flag = True
            break
    if not flag:
        print(nxt[0])
