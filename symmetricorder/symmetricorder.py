n = int(input())
ttl = 1
while n != 0:
    arr = []
    for _ in range(n):
        arr.append(input().strip())
    arr.sort(key=lambda x: len(x))
    ans = [""] * n
    front = 0
    back = n - 1
    for i in range(n):
        if i % 2 == 0:
            ans[front] = arr[i]
            front += 1
        else:
            ans[back] = arr[i]
            back -= 1
    print(f"SET {ttl}")
    for name in ans:
        print(name)
    ttl += 1
    n = int(input())