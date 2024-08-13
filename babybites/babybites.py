n = int(input())

arr = input().split(" ")
count = 1

flag = True
for elem in arr:
    if elem == "mumble":
        pass
    else:
        if int(elem) != count:
            print("something is fishy")
            flag = False
            break
    count += 1

if flag:
    print("makes sense")
