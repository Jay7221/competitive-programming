import os
import subprocess
import filecmp

INPUT_FOLDER = 'input'
OUTPUT_FOLDER = 'output'
EXPECTED_OUTPUT_FOLDER = 'expected_output'

SOLUTION_EXECUTABLE = 'main'

def run_solution(input_file, output_file):
    """
    Runs the solution executable with the given input file and writes the output to the specified output file.
    """
    subprocess.run(['./' + SOLUTION_EXECUTABLE], stdin=open(input_file, 'r'), stdout=open(output_file, 'w'))

def test_solution(input_file, expected_output_file):
    """
    Tests the solution executable with the given input file and compares the output with the expected output file.
    """
    # Generate output file path
    output_file = os.path.join(OUTPUT_FOLDER, os.path.splitext(os.path.basename(input_file))[0] + '.out')
    
    # Run the solution with the input file
    run_solution(input_file, output_file)
    
    # Compare the generated output file with the expected output file
    return filecmp.cmp(output_file, expected_output_file)

def run_tests():
    """
    Runs tests for all input files and compares the results with expected output files.
    """
    for input_file in os.listdir(INPUT_FOLDER):
        if input_file.endswith('.in'):
            input_file_path = os.path.join(INPUT_FOLDER, input_file)
            expected_output_file_path = os.path.join(EXPECTED_OUTPUT_FOLDER, input_file.replace('.in', '.out'))
            if not os.path.exists(expected_output_file_path):
                print(f"Expected output file '{expected_output_file_path}' not found.")
                continue
            result = test_solution(input_file_path, expected_output_file_path)
            if result:
                print(f"Test passed for input file '{input_file}'.")
            else:
                print(f"Test failed for input file '{input_file}'.")

if __name__ == "__main__":
    run_tests()

