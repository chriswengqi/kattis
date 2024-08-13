n = int(input())
arr = [*map(int, input().split())]
dic = {}
for num in arr:
    if num not in dic:
        dic[num] = 0
    dic[num] += 1
divisors = sorted(dic.items(), reverse=True)
first = -1
for k, v in divisors:
    if first == -1:
        first = k
    if first % k != 0 or v == 2:
        print(k, first)
        break



