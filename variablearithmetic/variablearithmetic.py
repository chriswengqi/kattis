import sys

dic = {}

for line in sys.stdin:
    if line.strip() == '0':
        break
    line = line.strip()
    if "=" in line:
        arr = [*line.split()]
        dic[arr[0]] = int(arr[2])
    else:
        arr = [*line.split()]
        ## print(arr)
        ans = 0
        tmp = []
        for word in arr:
            if word == '+': continue
            if word.isnumeric():
                ans += int(word)
            elif word in dic:
                ans += dic[word]
            else: tmp.append(word)
        if len(tmp) != 0 and ans != 0:
            print(ans, "+", " + ".join(tmp))
        elif ans == 0:
            print(" + ".join(tmp))
        else:
            print(ans)
