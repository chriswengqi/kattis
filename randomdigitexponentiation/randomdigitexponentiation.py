a, b = map(int, input().split())
arr = []
while a > 0:
    arr.append(a % 10)
    a //= 10
stack = []
def dfs(idx, curr):
    if idx == len(arr):
        if curr == b:
            print(" ".join(map(str, stack[::-1])))
            exit(0)
        else:
            return
    for i in range(33):
        tmp = pow(arr[idx], i) * pow(10, idx) + curr
        if tmp > b:
            return
        if tmp % pow(10, idx + 1) == b % pow(10, idx + 1):
            stack.append(i)
            dfs(idx + 1, tmp)
            stack.pop()

dfs(0, 0)


