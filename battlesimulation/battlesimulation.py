s = input().strip()

i = 0
n = len(s)
ans = []
dic = {'R':'S','B':'K','L':'H'}
while i < n:
    if 'R' in s[i:i+3] and 'B' in s[i:i+3] and 'L' in s[i:i+3]:
        ans.append('C')
        i += 3
    else:
        ans.append(dic[s[i]])
        i += 1
print("".join(ans))

