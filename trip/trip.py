n = int(input())

while n != 0:
    ttl = 0
    arr = []
    for i in range(n):
        s = input().strip()
        dd, cc = map(int, s.split("."))
        arr.append(dd * 100 + cc)
        ttl += dd * 100 + cc
    avg = ttl // n
    rem = ttl % n
    arr.sort(key=lambda x: abs(x - avg))
    print(arr, avg)
    ans = 0
    for num in arr:
        ans += max(0, avg)
    n = int(input())
    
