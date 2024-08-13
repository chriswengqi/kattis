import sys


def printt(date, points):
    date = str(date)
    print(
        f"{date[:4]}-{date[4:6]}-{date[6:]} {['No', abs(points)][points != 0]}{[' merit or', ''][points != 0]} {['merit', 'demerit'][points <= 0]} point{['(s)', 's'][points == 0]}."
    )


first = True
start = None
ans = []
for line in sys.stdin:
    if first:
        start = int(line.strip())
        first = False
    else:
        curr, num = map(lambda x: int(x), line.strip().split(" "))
        ans.append((curr, num))

curr = start

points = 0
printt(start, points)

for date, pts in ans:
    # reduce demerit points
    while curr + 10000 <= date and points < 0:
        points += max(-(points // 2), 2)
        points = min(points, 0)
        printt(curr + 10000, points)
        curr += 10000
    # increase merit points
    while curr + 20000 <= date and 0 <= points < 5:
        points += 1
        printt(curr + 20000, points)
        curr += 20000
    if points > 0 and points * 2 - pts <= 0:
        points = points * 2 - pts
    elif points > 0 and points * 2 - pts > 0:
        points = points - (pts // 2) - (pts % 2)
    else:
        points -= pts
    printt(date, points)
    curr = date

while points < 5:
    if points < 0:
        points += max(-(points // 2), 2)
        points = min(points, 0)
        printt(curr + 10000, points)
        curr += 10000
    else:
        points += 1
        printt(curr + 20000, points)
        curr += 20000
