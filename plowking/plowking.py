n,k=map(int,input().split())
print(sum(map(lambda i:min(i*(i-1)//2+1,k-n+i+1),range(1, n))))