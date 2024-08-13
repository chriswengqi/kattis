s = input()
n = len(s)
for i in range(1, n):
    if s[i] == 'O' and s[i] == s[i - 1]:
        print("INVALID")
        exit()
if s[-1] != 'O':
    print("INVALID")
    exit()
def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    else:
        return gcd(a % b, b)
a_num = 1
a_denom = 1
b_num = 0
b_denom = 1
for char in s[:-1]:
    if char == 'E':
        a_denom *= 2
        b_denom *= 2
    else:
        a_num *= 3
        b_num = (3 * b_num) + b_denom


print(a_num, a_denom, b_num, b_denom)
print((a_num * gcd(b_num, b_denom) + b_num) // b_denom)
