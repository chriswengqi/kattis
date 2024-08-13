n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append(input())
words = []
curr = []
for i in range(n):
    for j in range(m):
        if grid[i][j] == '#':
            if len(curr) > 1:
                words.append("".join(curr))
            curr = []    
        else:
            curr.append(grid[i][j])
    if len(curr) > 1:
        words.append("".join(curr))
    curr = []  
if len(curr) > 0:
    words.append("".join(curr))
    curr = []
for i in range(m):
    for j in range(n):
        if grid[j][i] == '#':
            if len(curr) > 1:
                words.append("".join(curr))
            curr = []    
        else:
            curr.append(grid[j][i])
    if len(curr) > 1:
        words.append("".join(curr))
    curr = []  
if len(curr) > 0:
    words.append("".join(curr))
    curr = []
words.sort()
print(words[0])
        