dic = {}
dic['a'] = '.-'
dic['b'] = '-...'
dic['c'] = '-.-.'
dic['d'] = '-..'
dic['e'] = '.'
dic['f'] = '..-.'
dic['g'] = '--.'
dic['h'] = '....'
dic['i'] = '..'
dic['j'] = '.---'
dic['k'] = '-.-'
dic['l'] = '.-..'
dic['m'] = '--'
dic['n'] = '-.'
dic['o'] = '---'
dic['p'] = '.--.'
dic['q'] = '--.-'
dic['r'] = '.-.'
dic['s'] = '...'
dic['t'] = '-'
dic['u'] = '..-'
dic['v'] = '...-'
dic['w'] = '.--'
dic['x'] = '-..-'
dic['y'] = '-.--'
dic['z'] = '--..'
dic['0'] = '-----'
dic['1'] = '.----'
dic['2'] = '..---'
dic['3'] = '...--'
dic['4'] = '....-'
dic['5'] = '.....'
dic['6'] = '-....'
dic['7'] = '--...'
dic['8'] = '---..'
dic['9'] = '----.'

s = input().strip()
ans = []
for char in s:
    if char.isalnum():
        if char.isalpha():
            char = char.lower()
        ans.append(dic[char])
if len(ans) == 0:
    print(0)
else:
    ss = "".join(ans)
    print([0, 1][ss == ss[::-1]])