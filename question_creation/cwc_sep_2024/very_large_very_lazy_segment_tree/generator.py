#! /bin/python3
import random

minN = 10 ** 8
maxN = 10 ** 9
minQ = 10 ** 4
maxQ = 10 ** 5
minX = 1
maxX = 10 ** 9

N = random.randint(minN, maxN)
Q = random.randint(minQ, maxQ)

def generate_query():
    l = random.randint(1, 100)
    r = random.randint(N - 100, N)
    x = random.randint(minX, maxX)
    return (l, r, x)

queries = [generate_query() for i in range(Q)]

print(f"{N} {Q}")
print("\n".join(' '.join([str(elem) for elem in query]) for query in queries))
