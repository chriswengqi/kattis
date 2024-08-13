N, K = map(lambda x: int(x) , input().split(" "))
dic = {}

def f(n, k):
    if n == 1:
        return 0
    elif (n, k) in dic:
        return dic[(n, k)]
    else:
        dic[(n , k)] = (f(n - 1, k) + k) % n
        return dic[(n, k)]
    

print(f(N, K))
    
    
