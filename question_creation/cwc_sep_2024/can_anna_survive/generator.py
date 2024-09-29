#!/bin/python3

import random

N = random.randint(10 ** 4, 10 ** 5)
y = random.randint(10 ** 8, 10 ** 9)
x = random.randint(y + 1, 10 ** 9)

arr = [random.randint(10 ** 8, 10 ** 9) for i in range(N)]

print(f"{N} {x} {y}")
print(' '.join([str(elem) for elem in arr]))
