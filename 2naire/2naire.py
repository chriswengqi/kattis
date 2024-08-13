n, k = input().split()
n, k = int(n), float(k)

def f(x, play_prob):
    if x == n:
        return 1
    else:
        return (1 - play_prob) + play_prob * 1.5 * f(x + 1, play_prob)

while n != 0 or k != 0:

    if k >= 0.5: ## play every round
        print(((1 + k)) ** n)
    else:
        print(f(0, 0.5 / (1 - k)))



    n, k = input().split()
    n, k = int(n), float(k)