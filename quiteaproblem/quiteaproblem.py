import sys

for line in sys.stdin:
    print(["no","yes"]["problem" in line.lower()])