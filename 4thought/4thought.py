def calculate(arr):
    stack = [4]

    for op in arr:
        if op == "/":
            prev = stack.pop()
            if prev >= 0:
                stack.append(prev // 4)
            else:
                stack.append(-1 * (-prev // 4))
        elif op == "*":
            prev = stack.pop()
            stack.append(prev * 4)
        elif op == "+":
            stack.append(4)
        else:
            stack.append(-4)
    return sum(stack)


op = ["+", "-", "*", "/"]

dic = {}
for i in range(len(op)):
    for j in range(len(op)):
        for k in range(len(op)):
            dic[calculate((op[i], op[j], op[k]))] = (op[i], op[j], op[k])

n = int(input())
for i in range(n):
    ans = int(input())
    if ans not in dic:
        print("no solution")
    else:
        print(f"4 {dic[ans][0]} 4 {dic[ans][1]} 4 {dic[ans][2]} 4 = {ans}")
