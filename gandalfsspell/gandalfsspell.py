s = input()

dic = {}
arr = input().split(" ")
flag = True
used = set()

if len(arr) != len(s):
    print("False")
    exit()

for i in range(len(arr)):
    if arr[i] not in dic and s[i] not in used:
        dic[arr[i]] = s[i]
        used.add(s[i])
    elif arr[i] not in dic and s[i] in used:
        flag = False
        break
    else:
        if dic[arr[i]] != s[i]:
            flag = False
            break

if flag:
    print("True")
else:
    print("False")
