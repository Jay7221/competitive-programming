def getArr():
    return list(map(int, input().split(' ')))
    return list(map(int, s.split(' ')))


d = getArr()
s = getArr()
c = getArr()
b = int(input())

n = len(s)

troops = {}
for cat in c:
    troops[cat] = []

for sz, dam, cat in zip(s, d, c):
    troops[cat].append([sz, dam])


dp = [0] * (b + 1)

for cat, arr in troops.items():
    for val in range(b, 0, -1):
        for sz, dam in arr:
            if sz <= val:
                dp[val] = max(dp[val], dp[val - sz] + dam)

print(max(dp), end='')
