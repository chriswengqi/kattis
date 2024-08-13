import sys

for line in sys.stdin:
    curr = line.strip().split()
    ttl = 0
    cnt = 0
    name = []
    for item in curr:
        if item.replace(".", "").isnumeric():
            ttl += float(item)
            cnt += 1
            
        else:
            name.append(item)
    print(ttl / cnt, " ".join(name))