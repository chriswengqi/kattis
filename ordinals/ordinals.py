n = int(input())

def f(x):
    if x == 0:
        return str({})
    else:
        arr = []
        for i in range(x):
            arr.append(f(i))
        ans = ",".join(arr)
        return "{" + ans + "}"
    
print(f(n))
    