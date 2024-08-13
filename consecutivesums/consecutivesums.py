n = int(input())

for i in range(n):
    k = int(input())
    curr = 2
    found = False
    arr = []
    while not found:
        if k // curr - curr // 2 < 0:
            break
        if curr % 2 == 1 and k % curr == 0:
            diff = curr // 2
            for j in range(k // curr - diff, k // curr + diff + 1):
                arr.append(j)
            found = True
        elif curr % 2 == 0 and k % curr == curr // 2:
            arr = []
            diff = curr // 2
            for j in range(k // curr - diff + 1, k // curr + diff + 1):
                arr.append(j)
            found = True
        curr += 1
    if not found:
        print("IMPOSSIBLE")
    else:
        print(f"{str(k)} = {' + '.join(map(str, arr))}")
