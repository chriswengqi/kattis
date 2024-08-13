n = int(input())

for i in range(n):
    sounds = list(input().strip().split(" "))
    dic = set(sounds)
    s = input().strip()
    while s != "what does the fox say?":
        arr = s.split(" ")
        dic.remove(arr[2])

        s = input().strip()

    sounds = [*filter(lambda x: x in dic, sounds)]
    print(" ".join(sounds))
