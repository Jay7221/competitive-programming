import random
import string

min_t = 1
max_t = 10 ** 4
min_n = 1
max_n = 10**3


s = random.randint(1, 3)
if s == 1:
    max_t = 2
    max_n = 10 ** 5
    min_n = max_n
elif s == 2:
    max_t = 100
    max_n = 10 ** 4


def randString(n):
    return ''.join([ random.choice(string.ascii_lowercase) for i in range(n)])

def generate_testcase(n):
    print(n)
    print(randString(n))


t = random.randint(min_t, max_t)
arr_n = [ random.randint(min_n, max_n) for i in range(t) ]


print(t)
for i in range(t):
    generate_testcase(arr_n[i])
l