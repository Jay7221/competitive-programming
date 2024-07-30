import os
import random

NUM_TEST_SETS = 15
MAX_N = 2 * 10 ** 3
MAX_MN = 2 * 10 ** 5
MAX_P = 10 ** 9
INPUT_FOLDER = 'input'
INPUT_EXTENSION = '.txt'

def generate_test_case(test_set_num):
    """
    Generates a single test case with multiple sub-cases.
    """
    N = random.randint(1, MAX_N)
    M = MAX_MN // N

    arr = [[random.randint(1, MAX_P) for _ in range(M)] for _ in range(N)]
    
    return (N, M, arr)

def print_test_case(file_path, test_case):
    """
    Writes the test cases to a file.
    """
    N, M, arr = test_case
    with open(file_path, 'w') as file:
        file.write(f"{N} {M}\n")
        file.write('\n'.join([
            ' '.join(map(str, row))
            for row in arr
        ]))

def generate_test_cases():
    """
    Generates test cases for the specified number of test case sets and writes them to files.
    """
    if not os.path.exists(INPUT_FOLDER):
        os.makedirs(INPUT_FOLDER)

    for i in range(1, NUM_TEST_SETS + 1):
        test_case = generate_test_case(i)
        file_path = os.path.join(INPUT_FOLDER, f'input0{i}{INPUT_EXTENSION}')
        print_test_case(file_path, test_case)

if __name__ == "__main__":
    generate_test_cases()

