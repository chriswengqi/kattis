a = [*map(lambda x: int(x) if x != "_" else "_", input().strip().split(" "))]
b = [*map(lambda x: int(x) if x != "_" else "_", input().strip().split(" "))]
ratios = [-1, -1, -1, -1]

adj = [[(0, 0)] * 4 for i in range(4)]


def gcd(a, b):
    if b > a:
        a, b = b, a
    if b == 0:
        return a
    if a % b == 0:
        return b
    else:
        return gcd(a % b, b)


for k in range(5):
    q = (a[2 * k], a[2 * k + 1], b[2 * k], b[2 * k + 1])
    for i in range(4):
        for j in range(i + 1, 4):
            if q[i] != "_" and q[j] != "_":
                adj[i][j] = (q[j] // gcd(q[i], q[j]), q[i] // gcd(q[i], q[j]))
                adj[j][i] = (q[i] // gcd(q[i], q[j]), q[j] // gcd(q[i], q[j]))
# print(adj)
# fill in the blanks:
for i in range(4):
    for j in range(4):
        if adj[i][j] == (0, 0):
            for k in range(4):
                if k != i and k != j:
                    if adj[i][k] != (0, 0) and adj[k][j] != (0, 0):
                        num = adj[i][k][0] * adj[k][j][0]
                        denom = adj[k][j][1] * adj[i][k][1]
                        adj[i][j] = (num // gcd(num, denom), denom // gcd(num, denom))

# fill in the blanks:
for i in range(4):
    for j in range(4):
        if adj[i][j] == (0, 0):
            for k in range(4):
                if k != i and k != j:
                    if adj[i][k] != (0, 0) and adj[k][j] != (0, 0):
                        num = adj[i][k][0] * adj[k][j][0]
                        denom = adj[k][j][1] * adj[i][k][1]
                        adj[i][j] = (num // gcd(num, denom), denom // gcd(num, denom))

# print(adj)
for i in range(5):
    q = [a[2 * i], a[2 * i + 1], b[2 * i], b[2 * i + 1]]
    for j in range(4):
        if q[j] != "_":
            for k in range(4):
                if k != j and adj[j][k][1] != 0:
                    q[k] = q[j] * adj[j][k][0] // adj[j][k][1]
            break
    a[2 * i], a[2 * i + 1], b[2 * i], b[2 * i + 1] = q
print(" ".join(map(str, a)))
print(" ".join(map(str, b)))
