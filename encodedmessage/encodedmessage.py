for _ in range(int(input())):
    s = input().strip()
    side = int(len(s) ** 0.5 + 1e9)
    grid = [[''] * side for _ in range(side)]
    for i in range(len(s)):
        grid[i // side][i % side] = s[i]
    print("".join([grid[j][i] for j in range(side) for i in range(side - 1, -1, -1)]))
