n = input()
while n != "0":
    a, b, c = map(int, n.split())
    bb = 0
    base = 1
    while b > 0:
        bb += base * (b % 10)
        b //= 10
        base *= a
    base = 1
    cc = 0
    while c > 0:
        cc += base * (c % 10)
        c //= 10
        base *= a
    rem = bb % cc
    arr = []
    while rem > 0:
        arr.append(rem % a)
        rem //= a
    print("".join(map(str, arr[::-1])) if len(arr) > 0 else 0)
        
    
    n = input()