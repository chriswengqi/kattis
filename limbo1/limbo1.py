n=int(input())
for _ in range(n):
    L,R=map(int,input().split())
    print((L+R)*(L+R+1)//2+R+1)