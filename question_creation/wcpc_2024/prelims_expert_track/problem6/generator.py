import os
import random

NUM_TEST_SETS = 2
MAX_ARRAY_SIZE = 2 * 10 ** 5
INPUT_FOLDER = 'input'
INPUT_EXTENSION = '.in'

def generate_test_case(test_set_num):
    """
    Generates a single test case with multiple sub-cases.
    """
    N = random.randint(1, MAX_ARRAY_SIZE)
    A = random.randint(1, N)
    B = random.randint(1, 10 ** 6)
    if A > B:
        tmp = B
        B = A
        A = tmp
    arr = [random.randint(-10 ** 9, 10 ** 9) for _ in range(N)]
    return (N, A, B, arr)

def print_test_case(file_path, test_case):
    """
    Writes the test cases to a file.
    """
    N, A, B, arr = test_case
    with open(file_path, 'w') as file:
        file.write(f"{N} {A} {B}" + '\n')
        file.write(' '.join(map(str, arr)))

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

