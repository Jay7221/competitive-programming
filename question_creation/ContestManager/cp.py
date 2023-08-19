import subprocess
import sys
import os
import re
import shutil

STATIC_MESSAGE = "THIS IS CPM - Competitive Programming Manager Tool to help you out on creating and managing Questions!"
TEMPLATE_PATH = '/home/oneautumleaf/Desktop/CompetitiveProgramming/Question_Creation/ContestManager'
PROBLEM_TEMPLATE = '/home/oneautumleaf/Desktop/CompetitiveProgramming/Question_Creation/ContestManager'
CONTEST_TEMPLATE = '/home/oneautumleaf/Desktop/CompetitiveProgramming/Question_Creation/ContestManager'

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

def run_executable(executable_path, input_path, output_path):
    if input_path == None:
        run_command(['./' + executable_path, '>', output_path])
    elif output_path == None:
        run_command(['./' + executable_path, '<', input_path])
    else:
        run_command(['./' + executable_path, '<', input_path, '>', output_path])


def run_file(file_path, input_paths = None, output_paths = None):

    if output_paths == None:
        output_paths = [None] * len(input_paths)
    if input_paths  == None:
        input_paths  = [None] * len(output_paths)

    if type(input_paths) != list:
        input_paths = [input_paths]
    if type(output_paths) != list:
        output_paths = [output_paths]

    run_command(['g++', '-o', 'main', file_path])
    for input_path, output_path in zip(input_paths, output_paths):
        if input_path != None:
            print(f"Executing on {os.path.basename(input_path)}")
        run_executable('generator', input_path, output_path)

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

    run_command(['g++', '-o', 'generator', 'generator.cpp'])
    inputs = []
    outputs = []
    for file in os.listdir(input_path):
        if re.match('input[0-9]*.txt', file):
            input_file = os.path.join(input_path, file)
            output_file = os.path.join(output_path, 'output' + file.lstrip('input'))
            inputs.append(input_file)
            outputs.append(output_file)
    run_file(generator_path, None, inputs)
    run_file(solution_path, inputs, outputs)

def makeInputFiles(path, noFiles):
    print("-----------------Creating Testcase Files--------------")
    input_path = os.path.join(path, 'inputs')
    for file in os.listdir(input_path):
        if re.match('input[0-9]*.txt', file):
            os.remove(os.path.join(input_path, file))
    file_path = os.path.join(input_path, 'input')
    for i in range(1, noFiles + 1):
        os.mknod(file_path + str(i) + '.txt')


def run(path):
    print("----------------- Running Testcases ----------------")
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

    inputs = []
    outputs = []
    for file in os.listdir(input_path):
        if file.startswith('input'):
            input_file = os.path.join(input_path, file)
            output_file = os.path.join(output_path, 'output' + file.lstrip('input'))
            inputs.append(input_file)
            outputs.append(output_file)
    run_file(solution_path, inputs, outputs)

def newContest(path, name):
    print(f"------------- Creating new Contest at location {path}, with name {name} ---------------------")
    shutil.copytree(CONTEST_TEMPLATE, os.path.join(path, name))


def newProblem(path, name):
    print(f"------------- Creating new Problem at location {path}, with name {name} ---------------------")
    shutil.copytree(PROBLEM_TEMPLATE, os.path.join(path, name))

def cmdHelper(args):
    if len(args) == 1:
        print(STATIC_MESSAGE)
        return
    if args[1] == 'new':
        if len(args) == 2:
            print("Please specify a name for the contest!!")
            return
        name = '_'.join(args[2:])
        newProblem(os.getcwd(), name)
    if args[1] == 'generate':
        if len(args) > 2:
            makeInputFiles(os.getcwd(), int(args[2]))
        generate(os.getcwd())
    if args[1] == 'trim':
        print(f"Trimming {os.getcwd()}")
        trim(os.getcwd())
    if args[1] == 'newcontest':
        if len(args) == 2:
            print("Please specify a name for the contest!!")
            return
        name = '_'.join(args[2:])
        newContest(os.getcwd(), name)
    if args[1] == 'run':
        run(os.getcwd())

if __name__=="__main__":
    cmdHelper(sys.argv)
