n = int(input())

dic = {}
def primeFactors(n):
    curr = n
    if n in dic:
        return dic[n]
    ans = []
    while n % 2 == 0:
        ans.append(2)
        n //= 2
    i = 3
    while i * i <= n:
        while n % i == 0:
            ans.append(i)
            n //= i
        i += 2
    if n > 1:
        ans.append(n)
    if len(ans) == 1:
        dic[curr] = (ans[0], 1)
        return (ans[0], 1)
    else:
        res, cnt = primeFactors(sum(ans))
        dic[curr] = (res, cnt + 1)
        return (res, cnt + 1)


while n != 4:
    res, cnt = primeFactors(n)
    print(res, cnt)

    n = int(input())