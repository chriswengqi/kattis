import sys

dic = {}
add = True

for line in sys.stdin:
    line = line.strip()
    if line == "":
        add = False
        continue
    if add:
        k, v = line.split(" ")
        dic[v] = k
    else:
        if line in dic:
            print(dic[line])
        else:
            print("eh")
