n = int(input())
while n != 0:

    arr = []
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    for _ in range(n):
        s, t = input().split()
        s = int(s)
        t = int(float(t) * 100 + 1e-6)
        arr.append((int(s), t))
        dp[_ + 1] = arr[_][1] + dp[_]

    max_profit = 0
    start = 0
    end = 0

    for i in range(n):
        for j in range(i, n):
            curr = dp[j + 1] - dp[i] - (arr[j][0] - arr[i][0] + 1) * 8
            if curr > max_profit:
                max_profit = curr
                start = arr[i][0]
                end = arr[j][0]
            elif curr == max_profit and (arr[j][0] - arr[i][0] < end - start):
                start = arr[i][0]
                end = arr[j][0]
            elif curr == max_profit and (arr[j][0] - arr[i][0] == end - start):
                if arr[i][0] < start:
                    start = arr[i][0]
                    end = arr[j][0]

    if max_profit > 0:
        x = max_profit // 100
        y = max_profit % 100
        print(f"{int(x)}.{int(y)} {start} {end}")
    else:
        print("no profit")

    n = int(input())