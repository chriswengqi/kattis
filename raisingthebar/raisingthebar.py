n, k = map(int, input().split())

dic = {}
ctr = 1
while True:
    n *= 10
    if n % k == 0:
        print(ctr, 0)
        break
    elif (n // k, n % k) in dic:
        print(dic[(n // k, n % k)] - 1, ctr - dic[(n // k, n % k)])
        break
    else:
        dic[(n // k, n % k)] = ctr
        n = n % k
        ctr += 1

