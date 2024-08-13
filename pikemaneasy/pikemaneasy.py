n, k = map(int, input().split())
a, b, c, d = map(int, input().split())
times = []
times.append(d)
mod = 1000000007

dic = {}
dic[d] = 0
cycle_start, cycle_end = -1, -1

for i in range(1, min(n,c) + 1):
    val = (a * times[-1] + b) % c + 1
    if val in dic:
        cycle_start = dic[val]
        cycle_end = i - 1
        break
    times.append(val)
    dic[val] = i

if cycle_start == -1:
    times.sort()
    total_time, total, total_penalty = 0, 0, 0
    for i in range(n):
        if total_time + times[i] <= k:
            total_time += times[i]
            total += 1
            total_penalty = (total_penalty + total_time) % mod
        else:
            break
    print(total, total_penalty)
else:
    cycle_size = cycle_end - cycle_start + 1
    dic2 = {}
    for i in range(cycle_start):
        dic2[times[i]] = 1
    for i in range(cycle_start, cycle_end + 1):
        if times[i] not in dic2:
            dic2[times[i]] = 0
        residue = (n - cycle_start) % cycle_size
        dic2[times[i]] += (n - cycle_start) // cycle_size + [0, 1][i - cycle_start < residue]
    total = 0
    total_time = 0
    penalty = 0
    dic2 = sorted(dic2.items(), key = lambda x: x[0])
    for key, v in dic2:
        if total_time + key * v <= k:
            total += v
            penalty += (total_time * v) + key * v * (v + 1) // 2
            penalty %= mod
            total_time += key * v
        else:
            curr_v = (key - total_time) // k
            total += curr_v
            penalty += (total_time * curr_v) + k * curr_v * (curr_v + 1) // 2
            penalty %= mod
            break
    print(total, penalty)
