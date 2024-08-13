n, k = map(lambda x: int(x), input().split())


arr = [i for i in range(1, n + 1)]
swaps = []
curr = n - 1
while k > 0:
    swaps.append(min(k, curr) - 1)
    k -= min(k, curr)
    curr -= 1


if len(swaps) != 0:
    curr = swaps[0] + 1
    for i in range(1, len(swaps)):
        if swaps[i] == swaps[i - 1] - 1:
            continue
        else:
            right = swaps[i - 1]
            while curr > right:
                arr[curr], arr[right] = arr[right], arr[curr]
                curr -= 1
                right += 1
            curr = swaps[i] + 1

    right = swaps[-1]
    while curr > right:
        arr[curr], arr[right] = arr[right], arr[curr]
        curr -= 1
        right += 1
print(" ".join(map(lambda x: str(x), arr)))
