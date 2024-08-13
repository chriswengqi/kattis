n,k=map(int,input().split());print(max([*map(lambda x:int(x[0])*int(x[1])*int(x[2])-k,[input().split() for _ in range(n)])]))
