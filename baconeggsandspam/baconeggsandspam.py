n = int(input())

while n != 0:
    dic = {}
    for i in range(n):
        arr = input().split(" ")
        for i in range(1, len(arr)):
            if arr[i] not in dic:
                dic[arr[i]] = [arr[0]]
            else:
                dic[arr[i]].append(arr[0])

    ans = sorted(dic.items(), key=lambda x: x[0])
    for k, v in ans:
        print(f"{k} {' '.join(sorted(v))}")
    n = int(input())
