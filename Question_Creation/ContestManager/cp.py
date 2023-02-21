import subprocess
import sys
import os
import re

STATIC_MESSAGE = "THIS IS CPM - Competitive Programming Manager Tool to help you out on creating and managing Questions!"

def run_command(args):
    os.system(' '.join(args))
    # subprocess.run(args)

def isExecutable(path):
    return os.access(path, os.X_OK)

def trim(path):
    if os.path.isdir(path):
        dirname = os.path.basename(path)
        if dirname == '.git':
            print("Ignoring directory .git")
        else:
            for file in os.listdir(path):
                trim(os.path.join(path, file))
    else:
        filename = os.path.basename(path)
        file_extension = os.path.splitext(filename)[1]
        if isExecutable(path) and (file_extension == '.exe' or file_extension == ''):
            print(f"Deleting executable file : {path}");
            os.remove(path);

def run_file(file_path, input_paths = None, output_paths = None):
    if type(input_paths) != list:
        input_paths = [input_paths]
        output_paths = [output_paths]
    run_command(['g++', '-o', 'main', file_path])
    for input_path, output_path in zip(input_paths, output_paths):
        print(f"Executing on {os.path.basename(input_path)}")
        run_command(['./main', '<', input_path, '>', output_path])

def generate(path):
    print("----------------- Generating Testcases ----------------")
    input_path = os.path.join(path, 'inputs')
    output_path = os.path.join(path, 'outputs')
    expected_output_path = os.path.join(path, 'expected_outputs')
    solution_path = os.path.join(path, 'solution.cpp')
    generator_path = os.path.join(path, 'generator.cpp')

    if not os.path.exists(output_path):
        os.mkdir(output_path)

    if not os.path.exists(expected_output_path):
        os.mkdir(expected_output_path)

    if not os.path.exists(input_path):
        os.mkdir(input_path)
    elif os.path.isfile(input_path):
        print("FILE by name of testcases in place of directory!!")
        return

    for file in os.listdir(input_path):
        inputs = []
        outputs = []
        if file.startswith('input'):
            input_file = os.path.join(input_path, file)
            output_file = os.path.join(output_path, 'output' + file.lstrip('input'))
            inputs.append(input_file)
            outputs.append(output_file)
        run_file(solution_path, inputs, outputs)

def run(path):
    print("----------------- Generating Testcases ----------------")
    input_path = os.path.join(path, 'inputs')
    output_path = os.path.join(path, 'outputs')
    expected_output_path = os.path.join(path, 'expected_outputs')
    solution_path = os.path.join(path, 'solution.cpp')

    if not os.path.exists(output_path):
        os.mkdir(output_path)

    if not os.path.exists(expected_output_path):
        os.mkdir(expected_output_path)

    if not os.path.exists(input_path):
        os.mkdir(input_path)
    elif os.path.isfile(input_path):
        print("FILE by name of testcases in place of directory!!")
        return

    for file in os.listdir(input_path):
        inputs = []
        outputs = []
        if file.startswith('input'):
            input_file = os.path.join(input_path, file)
            output_file = os.path.join(output_path, 'output' + file.lstrip('input'))
            inputs.append(input_file)
            outputs.append(output_file)
        run_file(solution_path, inputs, outputs)


def cmdHelper(args):
    if len(args) == 1:
        print(STATIC_MESSAGE)
        return
    if args[1] == 'new':
        pass
    if args[1] == 'generate':
        generate(os.getcwd())
    if args[1] == 'trim':
        print(f"Trimming {os.getcwd()}")
        trim(os.getcwd())
    if args[1] == 'newcontest':
        pass
    if args[1] == 'run':
        run(os.getcwd())

if __name__=="__main__":
    cmdHelper(sys.argv)
