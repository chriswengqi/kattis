
dic = {}

def dfs(rem):
    if rem == 0:
        return 1
    ans = 0
    if rem in dic:
        return dic[rem]
    for i in range(2, rem + 1, 2):
        if i == 2:
            ans += 3 * dfs(rem - i)
        else:
            ans += 2 * dfs(rem - i)
    dic[rem] = ans
    return ans

n = int(input())

while n != -1:
    if n % 2 == 1:
        print(0)
    else:
        print(dfs(n))

    n = int(input())