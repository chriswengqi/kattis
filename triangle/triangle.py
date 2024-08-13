import sys
from math import log10
ctr = 1
for line in sys.stdin:
    n = int(line)
    ans = log10(3) + n * log10(1.5)
    print(f"Case {ctr}: {int(ans) + 1}")
    ctr += 1