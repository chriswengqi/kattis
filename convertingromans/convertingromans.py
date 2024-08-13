n = int(input())

dic = {'I': 1, 'V': 5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}

for _ in range(n):
    s = input().strip()
    stack = []
    for i in range(len(s)):
        if len(stack) == 0 or stack[-1] >= dic[s[i]]:
            stack.append(dic[s[i]])
        else:
            curr = dic[s[i]]
            while len(stack) > 0 and stack[-1] < curr:
                tmp = stack.pop()
                curr -= tmp
            stack.append(curr)
    print(stack)
    