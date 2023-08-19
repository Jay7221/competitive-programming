import os

def isExecutable(path):
    return os.access(path, os.X_OK)
def trim(path):
    if os.path.isdir(path):
        dirname = os.path.basename(path)
        if dirname == '.git':
            print(".git ignored")
            return 
        for file in os.listdir(path):
            trim(os.path.join(path, file))
    else:
        filename = os.path.basename(path)
        file_ext = os.path.splitext(filename)[1]
        if  file_ext == '.out' or file_ext == '.txt':
            os.remove(path)
        if isExecutable(path) and (file_ext == '.exe' or file_ext == ''):
            print("Deleting executable file : " + path)
            os.remove(path)


if __name__ == '__main__':
    trim('.')
