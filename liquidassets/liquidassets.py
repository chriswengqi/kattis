n = int(input())

arr = input().split(" ")
ans = []
for word in arr:
    new_word = []
    for char in word:
        if len(new_word) > 0 and char == new_word[-1]:
            continue
        new_word.append(char)
    op = []
    for i in range(len(new_word)):
        if i == 0 or i == len(new_word) - 1:
            op.append(new_word[i])
            continue
        if new_word[i] not in ["a", "e", "i", "o", "u"]:
            op.append(new_word[i])

    ans.append("".join(op))

print(" ".join(ans))
