N = 10 ** 5
import random
edges = []
for i in range(2, N + 1):
    edges.append([random.randint(1, i - 1), i])

print(N)
print(N - 1)
print(2)
print('\n'.join([f"{e[0]} {e[1]}" for e in edges]))
for i in range(N):
    print(random.randint(10 ** 9 - 5, 10 ** 9))
