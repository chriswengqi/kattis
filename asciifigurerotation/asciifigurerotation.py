n = int(input())


while True:
    arr = [[" "] * 100 for _ in range(n)]
    maxx = 0
    for i in range(n):
        s = input()
        maxx = max(maxx, len(s))
        for j in range(len(s)):
            arr[i][j] = s[j]
    grid = [[" "] * n for _ in range(maxx)]

    for i in range(maxx):
        for j in range(n):
            if arr[n - j - 1][i] == "+":
                grid[i][j] = "+"
            if arr[n - j - 1][i] == "-":
                grid[i][j] = "|"
            if arr[n - j - 1][i] == "|":
                grid[i][j] = "-"
    # print(grid)

    for i in range(maxx):
        print("".join(grid[i]))

    n = int(input())

    if n == 0:
        break
    print()
