s = input()

def gcd(a, b):
    if b > a:
        return gcd(b, a)
    if b == 0:
        return a
    else:
        return gcd(a % b, b)

def add(n1, n2, d1, d2):
    denom = d1 * d2 // gcd(d1, d2)
    n1 *= denom // d1
    n2 *= denom // d2
    sm = n1 + n2
    return (sm // gcd(sm, denom), denom // gcd(sm, denom))


while s.strip() != "0":
    s = s.strip()[:-3]
    arr = [*map(lambda x: int(x) if x != "." else ".", [*s])]
    while arr[-1] == arr[-2]:
        arr.pop()
    last = arr[-1]
    if last == 9:
        carry = 1
        arr[-1] = 0
        ptr = -2
        while carry == 1:
            if arr[ptr] == '.':
                ptr -= 1
            else:
                arr[ptr] += 1
                carry = (arr[ptr] // 10)
                arr[ptr] %= 10
                ptr -= 1
    if arr[0] == 1:
        print("1/1")
    else:
        ttl = 0
        numer1 = 0
        numer2 = 
        if arr[-1] != 0:
            power = pow(10, len(arr) - 3)
            second = pow(10, len(arr) - 2)
            for i in range(2, len(arr) - 1):
                ttl *= 10
                ttl += arr[i]
            
        else:
            power = pow(10, len(arr) - 2)
            for i in range(2, len(arr)):
                ttl *= 10
                ttl += arr[i]
            numer1 = ttl
            denom1 = power
            res = add(numer1, 0, denom1, 1)
            print(f"{res[0]}/{res[1]}")

        numer1 = ttl
        numer2 = arr[-1]
        denom1 = power
        denom2 = power * 9
        res = add(numer1, numer2, denom1, denom2)
        print(f"{res[0]}/{res[1]}")


                    




    s = input()