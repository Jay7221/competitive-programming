def possible(arr, target):
    dp = [False] * (target + 1)
    dp[0] = True
    for elem in arr:
        for i in range(target, elem - 1, -1):
            dp[i] |= dp[i - elem]
    return dp[target]

def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    MASK = (1 << n)
    ans = 0
    
    for mask in range(MASK):
        v = []
        cur = 0
        for i in range(n):
            if (1 & (mask >> i)):
                cur += a[i]
            else:
                v.append(a[i])
        
        if possible(v, cur):
            ans = max(ans, cur)
    
    print(ans)

if __name__ == "__main__":
    main()
