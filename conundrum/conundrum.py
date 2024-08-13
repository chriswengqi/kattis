s = input().strip()
print(sum([1 if s[i] != "PER"[i % 3] else 0 for i in range(len(s))]))