import os
import random

NUM_TEST_SETS = 20
MIN_Q = 1
MAX_Q = 10000
MIN_K = 1
MAX_K = 100000
MIN_VAL = 1
MAX_VAL = 10 ** 9
INPUT_FOLDER = 'input'
INPUT_EXTENSION = '.in'

def generate_val():
    return random.randint(MIN_VAL, MAX_VAL)

def generate_key():
    return random.randint(MIN_K, MAX_K)

def generate_test_case(test_set_num):
    """
    Generates a single test case with multiple sub-cases.
    """
    Q = random.randint(1, MAX_Q)
    beg = generate_val()
    rows = []
    for _ in range(Q):
        rtype = random.randint(1, 2)
        if rtype == 1:
            rows.append([rtype, generate_key(), generate_key(), generate_val()])
        else:
            rows.append([rtype, generate_key()])
    return (Q, beg, rows)

def print_test_case(file_path, test_case):
    """
    Writes the test cases to a file.
    """
    Q, beg, rows = test_case
    with open(file_path, 'w') as file:
        file.write(f"{Q} {beg}\n")
        file.write('\n'.join([' '.join(map(str, row)) for row in rows]))

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

