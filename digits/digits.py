x = input()

while x != "END":
    if x == "1":
        print(1)
    elif len(x) == 1:
        print(2)
    elif len(x) < 10:
        print(3)
    else:
        print(4)

    x = input()
