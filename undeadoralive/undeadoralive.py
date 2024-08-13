s = input()


if ":)" in s and ":(" in s:
    print("double agent")
elif ":)" in s:
    print("alive")
elif ":(" in s:
    print("undead")
else:
    print("machine")
