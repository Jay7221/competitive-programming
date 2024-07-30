from math import gcd

n = int(input())

g = 0
for i in range(2, n + 1):
    a = i // 2
    b = i 
    g = max(g, gcd(a, b))

l = n * (n - 1)

print(l - g)
