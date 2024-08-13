n=int(input())
while n!=-1:
    if n<10:print(n+10)
    else:
        a=[0]*10
        for i in range(9,1,-1):
            while n%i==0:
                a[i]+=1
                n//=i
        print(["".join([*map(lambda x:str(x[0])*x[1],enumerate(a))]),"There is no such number."][n>1])
    n=int(input())