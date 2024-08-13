s = input().strip()


def is_palindrome(arr):
    l = 0
    r = len(arr) - 1
    while l < r:
        if arr[l] != arr[r]:
            return False
        l += 1
        r -= 1
    return True


arr = []
for char in s:
    if char.isalpha():
        arr.append(char.lower())

for i in range(len(arr)):
    for j in range(i + 1, len(arr)):
        if is_palindrome(arr[i : j + 1]):
            print("Palindrome")
            exit()

print("Anti-palindrome")
