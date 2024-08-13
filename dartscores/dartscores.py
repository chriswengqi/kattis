tc = int(input())
for _ in range(tc):
    n = int(input())
    ans = 0
    for i in range(n):
        x, y = map(int, input().split())
        dist = x*x + y*y
        
        x = (dist // 20) + 1
        print(11 - x)