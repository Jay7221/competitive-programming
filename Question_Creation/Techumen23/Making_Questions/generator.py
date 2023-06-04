from random import *


T_min = 1
T_max = 10 ** 5
N_min = 1
N_max = 10 ** 9

T = randint(T_min, T_max)
N_arr = sample(range(N_min, N_max), T)

def generate(N):
    print(N)
    arr = sample(range(1, 10 ** 9), 4)
    for t in arr:
        print(t, end = ' ')
    print()

print(T)

for N in N_arr:
    generate(N)