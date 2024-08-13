n = int(input())
arr = [*map(int, input().split())]
print(sum(map(lambda x: 1 if x < 0 else 0, arr)))