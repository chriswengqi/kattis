s,t=set([*input()]),input()
p=0
for c in t:
    if c not in s:p += 1
    else:s.remove(c)
    if not s or p==10:
        print(["WIN", "LOSE"][p==10])
        break