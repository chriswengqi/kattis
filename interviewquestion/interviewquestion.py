a, b = map(lambda x: int(x), input().strip().split(" "))
arr = list(map(lambda x: int(x) if x.isnumeric() else x, input().strip().split(" ")))


def gcd(a, b):
    if b > a:
        a, b = b, a
    if b == 0:
        return a
    if a % b == 0:
        return b
    else:
        return gcd(a % b, b)


fizz = []
buzz = []
fizzbuzz = []


for i in range(a, b + 1):
    if arr[i - a] == "Fizz":
        fizz.append(i)
    elif arr[i - a] == "Buzz":
        buzz.append(i)
    elif arr[i - a] == "FizzBuzz":
        fizzbuzz.append(i)

f, bu, fb = 0, 0, 0
if len(fizzbuzz) == 1:
    fb = fizzbuzz[0]
    f = fb
    bu = fb
elif len(fizzbuzz) > 1:
    curr = gcd(fizzbuzz[0], fizzbuzz[1])
    for i in range(2, len(fizzbuzz)):
        curr = gcd(curr, fizzbuzz[i])
    fb = curr

if len(fizz) == 1:
    f = gcd(fb, fizz[0])
elif len(fizz) > 1:
    curr = gcd(fizz[0], fizz[1])
    for i in range(2, len(fizz)):
        curr = gcd(curr, fizz[i])
    f = gcd(f, curr)

if len(buzz) == 1:
    bu = gcd(fb, buzz[0])
elif len(buzz) > 1:
    curr = gcd(buzz[0], buzz[1])
    for i in range(2, len(buzz)):
        curr = gcd(curr, buzz[i])
    bu = gcd(bu, curr)

if f == 0:
    f = b + 1 if fb == 0 else fb
if bu == 0:
    bu = b + 1 if fb == 0 else fb

print(f, bu)
