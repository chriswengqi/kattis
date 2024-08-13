n = int(input())
fib = [1,1]
while fib[-1] <= n:
    fib.append(fib[-1] + fib[-2])
ans = []
curr = len(fib) -1
while curr >= 0 and n >= 0:
    if n >= fib[curr]:
        ans.append(fib[curr])
        n -= fib[curr]
    else:
        curr -= 1
ans.reverse()
print(" ".join(map(str, ans)))