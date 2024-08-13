n = int(input())
ctrl = [0, 0, 0]
c = 0
v = 0
vacc = [0, 0, 0]
for i in range(n):
    s = input().strip()
    if s[0] == 'Y':
        v += 1
        vacc[0] += [0,1][s[1] == 'Y']
        vacc[1] += [0,1][s[2] == 'Y']
        vacc[2] += [0,1][s[3] == 'Y']
    else:
        c += 1
        ctrl[0] += [0,1][s[1] == 'Y']
        ctrl[1] += [0,1][s[2] == 'Y']
        ctrl[2] += [0,1][s[3] == 'Y']


ir = [*map(lambda x: x / v * 100, vacc)]
cr = [*map(lambda x: x / c * 100, ctrl)]

for i in range(3):
    if ir[i] >= cr[i]:
        print("Not Effective")
    else:
        print((cr[i] - ir[i]) / cr[i] * 100)

