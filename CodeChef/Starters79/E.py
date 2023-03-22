def check(k, x):
    return (((k - x + 1) ** 3) > k ** 2)
def solve():
    l = 0
    r = 100000000000
    x = int(input())
    while l < r:
        m = (l + r) // 2
        if check(m, x):
            r = m
        else:
            l = m + 1
    print(l * l)

T = int(input())
for t in range(0, T):
    solve()
