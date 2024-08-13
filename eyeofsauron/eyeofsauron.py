s = input().strip()
print(s, s[::-1])
print(["fix","correct"][s == s[::-1]])