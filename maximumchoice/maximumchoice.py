n,b=map(int,input().split())
curr,times=1,0
while curr<=n:
    curr*=b+1
    times+=1
print(times)