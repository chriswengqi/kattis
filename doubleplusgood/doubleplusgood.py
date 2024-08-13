arr = [*map(int, input().split("+"))]
bit = len(arr) - 1
ans = set()


for i in range(1 << bit):
    stack = [arr[0]]
    for j in range(1, len(arr)):
        if i & (1 << (j - 1)):
            curr = stack.pop()
            stack.append(curr * pow(10, len(str(arr[j]))) + arr[j])
        else:
            stack.append(arr[j])
    ans.add(sum(stack))

print(len(ans))
