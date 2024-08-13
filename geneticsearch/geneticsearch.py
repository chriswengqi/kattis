s=input()
while s.strip()!="0":
    a,b=s.split()
    x,y,z,w=0,0,0,len(a)
    for i in range(len(b)):
        if b[i:i+w]==a:x+=1
        if b[i:i+w-1] in [a[:i]+a[i+1:] for i in range(w)]:y+=1
        C = b[i:i+w+1]
        if a in [C[:j]+C[j+1:] for j in range(len(C))]:z+=1
    print(x,y,z)
    s=input()