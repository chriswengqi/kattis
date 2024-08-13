n = int(input())
dic = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
arr1 = [*input().strip().split()]
arr2 = [*input().strip().split()]

if [*reversed(arr1)] == arr2:
    
    print("Retrograde")
else:
    mapped1 = [*map(lambda x: dic.index(x), arr1)]
    mapped2 = [*map(lambda x: dic.index(x), arr2)]
    diff1 = []
    diff2 = []
    for i in range(1, n):
        diff1.append((mapped1[i] - mapped1[i - 1]) % 12)
        diff2.append((mapped2[i] - mapped2[i - 1]) % 12)
    if diff1 == diff2:
        print("Transposition")
    elif mapped1[0] == mapped2[0] and diff1 == [*map(lambda x: 12 - x if x != 0 else 0, diff2)]:
        print("Inversion")
    else:
        print("Nonsense")

