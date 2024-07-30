import os
import random

NUM_TEST_SETS = 10
MAX_TEST_CASES = 200
MAX_ARRAY_LENGTH = 10**5
MAX_ELEMENT_VALUE = 10**6
MIN_ARRAY_LENGTH = 1
INPUT_FOLDER = 'input'
INPUT_EXTENSION = '.in'

def generate_test_case(test_case_num):
    """
    Generates a single test case with multiple sub-cases.
    """
    T = random.randint(1, MAX_TEST_CASES)
    remaining_N = 2 * 10**5  # Remaining length of array A
    test_cases = []  # List to hold multiple test cases
    for _ in range(T):
        max_N = min(remaining_N, MAX_ARRAY_LENGTH)  # Maximum length for this test case
        max_N = max(max_N, MIN_ARRAY_LENGTH)
        N = random.randint(1, max_N)  # Length of array A for this test case
        remaining_N -= N
        A = [random.randint(-MAX_ELEMENT_VALUE, MAX_ELEMENT_VALUE) for _ in range(N)]  # Generate array A
        test_cases.append((N, A))
    return T, test_cases

def print_test_case(file_path, T, test_cases):
    """
    Writes the test cases to a file.
    """
    with open(file_path, 'w') as file:
        file.write(str(T) + '\n')
        for N, A in test_cases:
            file.write(str(N) + '\n')
            file.write(" ".join(map(str, A)) + '\n')

def generate_test_cases():
    """
    Generates test cases for the specified number of test case sets and writes them to files.
    """
    if not os.path.exists(INPUT_FOLDER):
        os.makedirs(INPUT_FOLDER)

    for i in range(1, NUM_TEST_SETS + 1):
        T, test_cases = generate_test_case(i)
        file_path = os.path.join(INPUT_FOLDER, f'0{i}{INPUT_EXTENSION}')
        print_test_case(file_path, T, test_cases)

if __name__ == "__main__":
    generate_test_cases()
