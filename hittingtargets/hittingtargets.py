n = int(input())
shapes = []
for i in range(n):
    x = input().split()
    curr = [x[0]]
    curr.extend([*map(int, x[1:])])
    shapes.append(curr)
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    ans = 0
    for jj in range(n):
        j = shapes[jj]
        
        if j[0] == "rectangle" and j[1] <= x <= j[3] and j[2] <= y <= j[4]:
            ans += 1
        if j[0] == "circle" and (x - j[1]) ** 2 + (y - j[2]) ** 2 <= j[3] ** 2:
            ans += 1
    print(ans)