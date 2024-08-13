n = int(input())

while n != 0:
    max_length = 0
    arr = []
    for i in range(n):
        a, op, b = input().split(" ")
        a = int(a)
        b = int(b)
        ans = 0
        if op == "+":
            ans = a + b
        elif op == "-":
            ans = a - b
        else:
            ans = a * b
        max_length = max(max_length, len(str(ans)))
        arr.append(str(ans))
    ans = []
    curr = []
    curr_length = 0
    for i in range(len(arr)):
        if curr_length == 0:
            curr = [" " * (max_length - len(arr[i])) + arr[i]]
            curr_length = max_length
        elif curr_length + max_length + 1 > 50:
            ans.append(curr)
            curr = [" " * (max_length - len(arr[i])) + arr[i]]
            curr_length = max_length
        else:
            curr.append(" " * (max_length + 1 - len(arr[i])) + arr[i])
            curr_length += max_length + 1
    ans.append(curr)
    for a in ans:
        print("".join(a))

    n = int(input())
    if n != 0:
        print("")
