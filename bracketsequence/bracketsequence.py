n = int(input())
arr = input().split(" ")

flag = 0  # 0 is +, 1 is *
stack = []
for char in arr:
    if char == "(":
        flag = 1 - flag
        stack.append("(")
    elif char == ")":
        curr = []
        while stack[-1] != "(":
            curr.append(stack.pop())
        stack.pop()
        if not flag:
            ans = 0
            for num in curr:
                ans += num
            stack.append(ans)
        else:
            ans = 1
            for num in curr:
                ans *= num
            stack.append(ans)
        flag = 1 - flag

    else:
        stack.append(int(char))


ans = 0
for elem in stack:
    ans += elem

print(ans % 1000000007)
