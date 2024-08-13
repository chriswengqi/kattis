import sys
dic = {}
for line in sys.stdin:
    ans = []
    words = line.strip().split()
    for word in words:
        w = word.lower()
        if w not in dic:
            dic[w] = 0
            ans.append(word)
        else:
            ans.append('.')
    print(" ".join(ans))




