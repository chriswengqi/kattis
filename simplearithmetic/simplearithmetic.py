a,b,c=map(int,input().split())
print(f"{a*b//c}.{str((a*b%c)/c)[2:]}")
