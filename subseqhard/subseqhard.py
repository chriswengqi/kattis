TC = int(input())


def solve():
    input()
    n = int(input())
    arr = list(map(lambda x: int(x), input().split(" ")))
    dic = {0: 1}
    ans = 0
    for i in range(len(arr)):
        new_dic = {0: 1}
        if arr[i] == 47:
            ans += 1
        print(dic)
        for k, v in dic.items():
            new_val = k + arr[i]
            if new_val == 47:
                ans += v
                print(new_val, v)
            elif new_val < 47:
                if new_val not in new_dic:
                    new_dic[new_val] = 0
                new_dic[new_val] += v
        dic = new_dic
    print(ans)


for _ in range(TC):
    solve()
