a, b = map(int, input().strip().split(":"))
start1 = a * 60 + b
a, b = map(int, input().strip().split(":"))
start2 = a * 60 + b
a, b = map(int, input().strip().split(":"))
diff1 = a * 60 + b
a, b = map(int, input().strip().split(":"))
diff2 = a * 60 + b
if start1 > start2:
    start1, start2 = start2, start1
    diff1, diff2 = diff2, diff1

# diff1 * x = diff2 * y + 640
rem = set()
y = 0
found = False
days = ["Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]
while not found:
    curr = diff2 * y + start2 - start1
    if curr % diff1 == 0:
        found = True
    if curr % diff1 in rem:
        break
    rem.add(curr % diff1)
    y += 1
if found:
    ans = (y - 1) * diff2 + start2
    day = ans // 1440
    hr = (ans % 1440) // 60
    minute = ans % 60
    print(days[day % 7])
    print(f"{hr:02d}:{minute:02d}")

else:
    print("Never")
