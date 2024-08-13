n=int(input())
pos=13%n-1
arr=[input() for _ in range(n)]
arr[0],arr[pos]=arr[pos],arr[0]
print("\n".join(arr))