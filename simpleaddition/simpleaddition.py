a = input().strip()
b = input().strip()
if len(a) < len(b):
    a = '0' * (len(b) - len(a)) + a
else:
    b = '0' * (len(a) - len(b)) + b
ans = []
carry = 0
for i in range(len(a)):
    curr = int(a[len(a) - i - 1]) + int(b[len(b) - i - 1]) + carry
    ans.append(curr % 10)
    carry = curr // 10
if carry == 1:
    ans.append(carry)
ans.reverse()
print("".join(map(str, ans)))