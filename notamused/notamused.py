import sys

dic = {}
dic2 = {}
day = 0
for line in sys.stdin:
    line = line.strip()

    if line == "OPEN":
        day += 1
        dic = {}
        dic2 = {}
    elif line == "CLOSE":
        print(f"Day {day}")
        lst = sorted(dic.items(), key=lambda x: x[0])
        for name, p in lst:
            print(f"{name} ${p // 10}.{p % 10}0")
        print("")
    else:
        command, name, time = line.split(" ")
        time = int(time)
        if command == "ENTER":
            dic2[name] = time
        else:
            if name not in dic:
                dic[name] = 0
            dic[name] += time - dic2[name]
