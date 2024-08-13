n = int(input())

for i in range(n):
    s = input().strip()
    chars = [0] * 26
    for char in s:
        if char.isalpha():
            chars[ord(char.lower()) - ord("a")] = 1
    if sum(chars) == 26:
        print("pangram")
    else:
        arr = []
        for i in range(26):
            if chars[i] == 0:
                arr.append(chr(ord("a") + i))
        print(f"missing {''.join(arr)}")
