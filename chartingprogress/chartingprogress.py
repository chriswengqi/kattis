import sys
curr = []
counts = []
for line in sys.stdin:
    line = line.strip()
    if line == "":
        ans = [['.'] * len(curr[0]) for _ in range(len(curr))]
        cnt = 0
        for i in range(len(curr)):
            for j in range(len(curr[0]) - 1 - cnt, len(curr[0]) - 1 - cnt - counts[i], -1):
                ans[i][j] = '*'
            cnt += counts[i]
        for line in ans:
            print("".join(line))
        print()
        curr = []
        counts = []
    else:
        curr.append(line)
        counts.append(line.count('*'))
ans = [['.'] * len(curr[0]) for _ in range(len(curr))]
cnt = 0
for i in range(len(curr)):
    for j in range(len(curr[0]) - 1 - cnt, len(curr[0]) - 1 - cnt - counts[i], -1):
        ans[i][j] = '*'
    cnt += counts[i]
for line in ans:
    print("".join(line))
        
