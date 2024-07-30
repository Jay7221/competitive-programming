import os
import random

NUM_TEST_SETS = 5
MAX_N = 2 * 10 ** 2
MAX_Q = 2 * 10 ** 2
INPUT_FOLDER = 'input'
INPUT_EXTENSION = '.in'

def generate_test_case(test_set_num):
    """
    Generates a single test case with multiple sub-cases.
    """
    N = random.randint(1, MAX_N)
    Q = random.randint(1, MAX_Q)
    s = ''.join([['a', 'b'][random.randint(0, 1)] for _ in range(N)])
    queries = []
    for _ in range(Q):
        t = random.randint(1, 3)
        L = random.randint(1, N)
        R = random.randint(1, N)
        if L > R:
            tmp = R
            R = L
            L = tmp
        queries.append((t, L, R))
    return (N, Q, s, queries)

def print_test_case(file_path, test_case):
    """
    Writes the test cases to a file.
    """
    N, Q, s, q = test_case
    with open(file_path, 'w') as file:
        file.write(f"{N}" + '\n')
        file.write(f"{s}" + '\n')
        file.write(f"{Q}" + '\n')
        for query in q:
            t, l, r = query
            file.write(f"{t} {l} {r}\n")

def generate_test_cases():
    """
    Generates test cases for the specified number of test case sets and writes them to files.
    """
    if not os.path.exists(INPUT_FOLDER):
        os.makedirs(INPUT_FOLDER)

    for i in range(1, NUM_TEST_SETS + 1):
        test_case = generate_test_case(i)
        file_path = os.path.join(INPUT_FOLDER, f'0{i}{INPUT_EXTENSION}')
        print_test_case(file_path, test_case)

if __name__ == "__main__":
    generate_test_cases()

