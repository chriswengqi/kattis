n = int(input())
arr = list(map(lambda x: int(x), input().split(" ")))
arr.reverse()

stack = []
for i in range(2 * n):
    if not stack:
        stack.append(arr[-1])
        arr.pop()

    elif stack[-1] == arr[-1]:
        stack.pop()
        arr.pop()
    else:
        stack.append(arr[-1])
        arr.pop()

if not stack and not arr:
    print(n * 2)
else:
    print("impossible")
