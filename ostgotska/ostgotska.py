arr = list(map(lambda x: 1 if "ae" in x else 0, input().strip().split()))
print("dae ae ju traeligt va") if sum(arr) / len(arr) >= 0.4 else print("haer talar vi rikssvenska")
    