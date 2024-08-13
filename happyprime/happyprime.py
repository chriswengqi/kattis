tc = int(input())

def is_prime(n):
    if n <= 1:
        return False
    curr = 2
    while curr * curr <= n:
        if n % curr == 0:
            return False
        curr += 1
    return True

for _ in range(tc):
    n, m = map(int, input().split())

    if not is_prime(m):
        print(n, m, "NO")
    else:
        s = set()
        tmp = m
        while tmp != 1 and tmp not in s:
            s.add(tmp)
            new_tmp = 0
            while tmp > 0:
                new_tmp += (tmp % 10) * (tmp % 10)
                tmp //= 10
            tmp = new_tmp
        if tmp == 1:
            print(n, m, "YES")
        else:
            print(n, m, "NO")