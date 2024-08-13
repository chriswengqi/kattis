n=int(input())
s=[input() for _ in range(n)] 
print(max([j-i+1 if len([*filter(lambda x:s[0][i:j+1] in x,s[1:])])==n-1 else 0 for i in range(len(s[0])) for j in range(i,len(s[0]))]))