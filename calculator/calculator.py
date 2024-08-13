import sys

for line in sys.stdin:
    x = str(round(eval(line), 2))
    if '.' not in x:
        print("".join([x, '.00']))
    elif x[-2] == '.':
        print("".join([x,'0']))
    else:
        print(x)
    
    