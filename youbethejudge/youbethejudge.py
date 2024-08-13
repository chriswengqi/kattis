import sys
ttl = []

def is_prime(n):
    if n <= 1:
        return False
    curr = 2
    while curr * curr <= n:
        if n % curr == 0:
            return False
        curr += 1
    return True

for line in sys.stdin:
    arr = line.split()
    arr = [*filter(lambda x: x != "", arr)]
    ttl.extend(arr)
if len(ttl) != 3:
    print(0)
else:
    for word in ttl:
        for char in word:
            if char not in "0123456789":
                print(0)
                exit()
    ttl = [*map(int, ttl)]
    prereq = ttl[0] > 3 and ttl[0] <= 1000000000 and is_prime(ttl[1]) and is_prime(ttl[2])

    if ttl[0] == ttl[1] + ttl[2] and prereq:
        print(1)
    else:
        print(0)
