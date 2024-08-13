n, k = map(lambda x: int(x), input().split(" "))
people = []
for i in range(k):
    people.append(input())
grid = []
for i in range(n):
    arr = list(map(lambda x: int(x) - 1, input().strip().split(" ")))
    arr.reverse()
    grid.append(arr)
first_votes = {}
for i in range(k):
    first_votes[i] = []
for i in range(len(grid)):
    first_votes[grid[i][-1]].append(i)
while len(max(first_votes.items(), key=lambda x: len(x[1]))[1]) < n // 2 + 1:
    loser, _ = min(first_votes.items(), key=lambda x: (len(x[1]), -x[0]))
    curr = first_votes[loser]
    first_votes.pop(loser)
    for v in curr:
        while grid[v][-1] not in first_votes:
            grid[v].pop()
        first_votes[grid[v][-1]].append(v)

print(people[max(first_votes.items(), key=lambda x: len(x[1]))[0]])
