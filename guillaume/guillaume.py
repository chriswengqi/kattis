n = int(input())
s = input()
rate = -1
ans = []
games = 0
wins = 0
for i in range(n - 1, -1, -1):
    if s[i] in "AG":
        games += 1
    if s[i] == "G":
        wins += 1
    if games != 0 and wins / games > rate:
        ans = [wins, games - wins]
        rate = wins / games
if ans != []:
    print(f"{ans[0]}-{ans[1]}")
else:
    print("0-0")
