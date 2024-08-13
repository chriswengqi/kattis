n = int(input())
cnt = 1
while n != 0:
    dic = {}
    for i in range(n):
        x = input().split(" ")
        animal = x[-1].lower()
        if animal not in dic:
            dic[animal] = 0
        dic[animal] += 1

    ans = sorted(dic.items(), key=lambda x: x[0])
    print(f"List {cnt}:")
    for animal, count in ans:
        print(f"{animal} | {count}")

    cnt += 1
    n = int(input())
