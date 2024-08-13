from math import log

N, K = map(lambda x: int(x), input().split(" "))

if log(N, 2) > K:
    print("You will become a flying monkey!")
else:
    print("Your wish is granted!")