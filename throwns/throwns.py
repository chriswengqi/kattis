n, k = map(lambda x: int(x), input().split(" "))
arr = list(input().split(" "))

stack = [0]
curr = 0
for i in range(k):
    if arr[curr] == "undo":
        x = int(arr[curr + 1])
        for j in range(x):
            stack.pop()
        curr += 2
    else:
        stack.append((stack[-1] + int(arr[curr])) % n)

        curr += 1


print(stack[-1])
