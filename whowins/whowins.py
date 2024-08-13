arr = []
for _ in range(3):
    curr = input().strip().split()
    arr.append("".join(curr))

pawns = ['X', 'O']
names = ['Johan', 'Abdullah']
for i in range(2):
    curr = pawns[i]
    for j in range(3):
        ttl = 0
        for k in range(3):
            ttl += [0, 1][arr[j][k] == curr]
        if ttl == 3:
            print(names[i], "har vunnit")
            exit()
    for j in range(3):
        ttl = 0
        for k in range(3):
            ttl += [0, 1][arr[k][j] == curr]
        if ttl == 3:
            print(names[i], "har vunnit")
            exit()
    ttl = 0
    for j in range(3):
        ttl += [0, 1][arr[j][j] == curr]
    if ttl == 3:
            print(names[i], "har vunnit")
            exit()
    ttl = 0
    for j in range(3):
        ttl += [0, 1][arr[2 - j][j] == curr]
    if ttl == 3:
            print(names[i], "har vunnit")
            exit()
print("ingen har vunnit")
    