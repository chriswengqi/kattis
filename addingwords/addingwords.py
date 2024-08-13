import sys

dic = {}
dic_num = {}
for line in sys.stdin:
    curr = line.strip().split(" ")
    command = curr[0]
    items = curr[1:]
    if command == "clear":
        dic.clear()
        dic_num.clear()
    elif command == "def":
        if items[0] not in dic:
            dic[items[0]] = int(items[1])
            dic_num[int(items[1])] = items[0]
        else:
            curr_num = dic[items[0]]
            dic_num.pop(curr_num)
            dic[items[0]] = int(items[1])
            dic_num[int(items[1])] = items[0]
    else:
        total = 0
        sign = 1
        ans = None
        flag = False
        for s in items:
            if s == "+":
                sign = 1
            elif s == "-":
                sign = -1
            elif s == "=":
                if total in dic_num:
                    ans = dic_num[total]
                else:
                    flag = True
            else:
                if s not in dic:
                    flag = True
                    break
                else:
                    total += dic[s] * sign
        if flag:
            items.append("unknown")
        else:
            items.append(ans)
        print(" ".join(items))
