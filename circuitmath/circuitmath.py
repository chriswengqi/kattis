n = int(input())
arr = [*map(lambda x: True if x == "T" else False, input().strip().split(" "))]
op = [*input().strip().split(" ")]

stack = []
for char in op:
    if char == "*":
        a = stack.pop()
        b = stack.pop()
        stack.append(a & b)
    elif char == "+":
        a = stack.pop()
        b = stack.pop()
        stack.append(a | b)
    elif char == "-":
        stack[-1] ^= True
    else:
        stack.append(arr[ord(char) - ord("A")])

if stack[-1] == 1:
    print("T")
else:
    print("F")
