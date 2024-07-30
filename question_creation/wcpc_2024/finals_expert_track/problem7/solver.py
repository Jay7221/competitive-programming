import os
import subprocess

INPUT_FOLDER = 'input'
OUTPUT_FOLDER = 'expected_output'
SOLUTION_EXECUTABLE = 'solution'
INPUT_EXTENSION = '.in'
OUTPUT_EXTENSION = '.out'

def run_solution(input_file, output_file):
    """
    Runs the solution executable with the given input file and writes the output to the specified output file.
    """
    subprocess.run(['./' + SOLUTION_EXECUTABLE], stdin=open(input_file, 'r'), stdout=open(output_file, 'w'))

def process_test_case(input_file):
    """
    Processes a single test case by running the solution executable with the input file and writing the output to
    the corresponding output file.
    """
    output_file = os.path.join(OUTPUT_FOLDER, os.path.splitext(os.path.basename(input_file))[0] + OUTPUT_EXTENSION)
    run_solution(input_file, output_file)

def process_test_cases():
    """
    Processes all test cases in the input folder.
    """
    if not os.path.exists(OUTPUT_FOLDER):
        os.makedirs(OUTPUT_FOLDER)

    for input_file in os.listdir(INPUT_FOLDER):
        if input_file.endswith(INPUT_EXTENSION):
            input_file_path = os.path.join(INPUT_FOLDER, input_file)
            process_test_case(input_file_path)

if __name__ == "__main__":
    process_test_cases()
