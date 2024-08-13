queue = []

for i in range(int(input())):
    queue.append(input())

for i in range(int(input())):
    curr = input().split(" ")
    if curr[0] == "cut":
        queue.insert(queue.index(curr[2]), curr[1])
    else:
        queue.remove(curr[1])

for p in queue:
    print(p)
