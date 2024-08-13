d, r, t = int(input()), int(input()), int(input())
rita, theo, ctr = 0, 0, 4
while True:
    rita += ctr
    theo += ctr - d if ctr - d >= 3 else 0
    ctr += 1
    if rita + theo == r + t:
        break
print(r - rita)
