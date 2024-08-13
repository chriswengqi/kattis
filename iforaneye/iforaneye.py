n = int(input())

dic = {}
dic["at"] = "@"
dic["and"] = "&"
dic["one"] = "1"
dic["won"] = "1"
dic["two"] = "2"
dic["too"] = "2"
dic["to"] = "2"
dic["for"] = "4"
dic["four"] = "4"
dic["bea"] = "b"
dic["be"] = "b"
dic["bee"] = "b"
dic["see"] = "c"
dic["sea"] = "c"
dic["eye"] = "i"
dic["oh"] = "o"
dic["owe"] = "o"
dic["are"] = "r"
dic["you"] = "u"
dic["why"] = "y"
for i in range(n):
    s = input()
    ans = []
    i = 0
    while i < len(s):
        if s[i : i + 4].lower() in dic:
            curr = dic[s[i : i + 4].lower()]
            if s[i].isupper():
                ans.append(curr.capitalize())
            else:
                ans.append(curr)
            i += 4
        elif s[i : i + 3].lower() in dic:
            curr = dic[s[i : i + 3].lower()]
            if s[i].isupper():
                ans.append(curr.capitalize())
            else:
                ans.append(curr)
            i += 3
        elif s[i : i + 2].lower() in dic:
            curr = dic[s[i : i + 2].lower()]
            if s[i].isupper():
                ans.append(curr.capitalize())
            else:
                ans.append(curr)
            i += 2
        else:
            ans.append(s[i])
            i += 1

    print("".join(ans))
