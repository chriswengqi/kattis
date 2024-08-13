board = []
my_k = (-1, -1)
his_k = (-1, -1)
my_r = (-1, -1)
for i in range(8):
    board.append(input())
    for j in range(8):
        if board[i][j] == 'K':
            my_k = (i, j)
        if board[i][j] == 'k':
            his_k = (i, j)
        if board[i][j] == 'R':
            my_r = (i, j)
Kx, Ky = my_k
kx, ky = his_k
Rx, Ry = my_r
def checkmate(kx, ky, Kx, Ky, Rx, Ry):
    if abs(Rx - kx) <= 1 and abs(Ry - ky) <= 1:
        return False
    board = [['*'] * 8 for _ in range(8)]
    for i in range(max(0,kx-1), min(8,kx+2)):
        for j in range(max(0, ky-1), min(8, ky+2)):
            board[i][j] = '-'
    for i in range(max(0,Kx-1), min(8,Kx+2)):
        for j in range(max(0, Ky-1), min(8, Ky+2)):
            board[i][j] = '*'
    for i in range(8):
        if i == Ry: continue
        board[Rx][i] = '*'
    for i in range(8):
        if i == Rx: continue
        board[i][Ry] = '*'
    ans = sum(map(lambda x: x.count('-'), board))
    return ans == 0
for i in range(1, 8):
    if Rx + i >= 8 or (Rx + i == Kx and Ry == Ky):
        break
    if checkmate(kx, ky, Kx, Ky, Rx + i, Ry):
        print("Yes")
        exit() 

for i in range(1, 8):
    if Ry + i >= 8 or (Rx == Kx and Ry + i == Ky):
        break
    if checkmate(kx, ky, Kx, Ky, Rx, Ry + i):
        print("Yes")
        exit() 

for i in range(1, 8):
    if Rx - i < 0 or (Rx - i == Kx and Ry == Ky):
        break
    if checkmate(kx, ky, Kx, Ky, Rx - i, Ry):
        print("Yes")
        exit() 

for i in range(1, 8):
    if Ry - i < 0 or (Rx == Kx and Ry - i == Ky):
        break
    if checkmate(kx, ky, Kx, Ky, Rx, Ry - i):
        print("Yes")
        exit() 

print("No")


