import sys

arr = []
max_length = 0

for line in sys.stdin:
    line = line.strip()
    if line == "":
        arr.sort(key=lambda x: x[::-1])
        for elem in arr:
            pad = " " * (max_length - len(elem))
            print(pad + elem)
        print("")
        max_length = 0
        arr.clear()
    else:
        arr.append(line)
        max_length = max(max_length, len(line))

arr.sort(key=lambda x: x[::-1])
for elem in arr:
    pad = " " * (max_length - len(elem))
    print(pad + elem)
