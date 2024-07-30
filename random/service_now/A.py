n = int(input())
m = n
while n > 10:
    d = n
    n = 0
    while d > 0:
        n += d % 10
        d = d // 10

print(n * m)
