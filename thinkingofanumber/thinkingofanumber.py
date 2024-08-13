n = int(input())

def gcd(a, b):
    if b > a:
        a, b = b, a
    if b == 0:
        return a
    if a % b == 0:
        return b
    else:
        return gcd(a % b, b)

while n != 0:
    lb = 0
    rb = 1e100
    lcm = 1
    for i in range(n):
        arr = [*input().split()]
        curr = int(arr[2])
        
        if arr[0] == "less":
            rb = min(curr, rb)
        elif arr[0] == "greater":
            lb = max(curr, lb)
        else:
            tmp = gcd(lcm, curr)
            lcm = lcm * curr // tmp
        
    if rb == 1e100:
        print("infinite")
    else:
        prev = (lb // lcm + 1) * lcm
        ans = []
        while prev < rb:
            ans.append(prev)
            prev += lcm
        if len(ans) == 0:
            print("none")
        else:
            print(" ".join(map(str, ans)))

    n  = int(input())