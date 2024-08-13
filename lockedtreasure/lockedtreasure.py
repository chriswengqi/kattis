tc = int(input())

for _ in range(tc):
    n, m = map(int, input().split())
    
    ans = 1
    for i in range(1, min(n - m, m)):
        ans *= (n - i)
        
    for i in range(2, max(n  - m, m)):
        ans //= i
        
    print(ans)