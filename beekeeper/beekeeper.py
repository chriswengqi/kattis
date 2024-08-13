n = int(input())
vowels = "aeiouy"
while n != 0:
    max_ttl = 0
    ans = ""
    for _ in range(n):
        ttl = 0
        s = input().strip()
        for i in range(1, len(s)):
            if s[i] in vowels and s[i - 1] in vowels and s[i] == s[i - 1]:
                ttl += 1
        if ttl > max_ttl:
            max_ttl = ttl
            ans = s
    print(ans)
                
        
    
    
    n = int(input())