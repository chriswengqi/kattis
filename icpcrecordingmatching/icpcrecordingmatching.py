import sys

i = []
o = []
mode = 0
for line in sys.stdin:
    line = line.strip()
    if line == "":
        mode = 1
        continue

    if mode == 0:
        x = line.split("\t")
        i.append(tuple(x))
    else:
        x = line.split("\t")
        flag = False
        for fname, lname, email in i:
            if (x[0].lower() == fname.lower() and x[1].lower() == lname.lower()) or x[
                2
            ].lower() == email.lower():
                i.remove((fname, lname, email))
                flag = True
                break
        if not flag:
            o.append(x)
if len(i) == 0 and len(o) == 0:
    print("No mismatches.")
else:
    if len(i) > 0:
        i.sort(key=lambda x: x[2].lower())
        for fname, lname, email in i:
            print(f"I {email} {lname} {fname}")
    if len(o) > 0:
        o.sort(key=lambda x: x[2].lower())
        for fname, lname, email in o:
            print(f"O {email} {lname} {fname}")
