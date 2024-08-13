s = input()
n = len(s)
pref = [0] * n
suf = [0] * n
for i in range(n):
    if i == 0:
        pref[i] = [0,1][s[i] == '>']
    else:
        pref[i] = pref[i - 1] + [0, 1][s[i] == '>']
for i in range(n - 1, -1, -1):
    if i == n - 1:
        suf[i] = [0, 1][s[i] == '<']
    else:
        suf[i] = suf[i + 1] + [0, 1][s[i] == '<']
ans = 0
for i in range(n):
    if i != n - 1 and s[i] == '>':
        ans += suf[i + 1]
print(ans) 