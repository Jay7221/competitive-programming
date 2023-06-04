from random import *


N_min = 1
N_max = 100
M_min = 1
M_max = 100


N = randint(N_min, N_max)
M = randint(M_min, M_max)

# N = 100
# M = 100
# testcase_type = randint(1, 2)
# if testcase_type == 1:
#     # Testcase will be an edge testcase of type 1
#     N = 100
# elif testcase_type == 2:
#     # Edge testcase of type 2
#     M = 100
# elif testcase_type == 3:
#     # Edge testcase of type 3
#     N = 100
#     M = 100

alpha = max(M - 5, 2)
def generate(n, m):
    print(n, m)
    for i in range(n):
        k = randint(1, m - alpha)
        print(k)
        a = sample(range(1, m + 1), k)
        for ai in a:
            print(ai, end=' ')
        print()
    return

generate(N, M)