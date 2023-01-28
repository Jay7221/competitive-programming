import os

def getSize(folderPath):
    size = 0
    for path, files, dirs in os.walk(folderPath):
        for file in files:
            filePath = os.path.join(path)
            size += os.path.getsize(filePath)
    return size

size = getSize('.')

GB = size // (10 ** 9)
size -= GB * (10 ** 9)

MB = size // (10 ** 6)
size -= MB * (10 ** 6)

KB = size // (10 ** 3)
size -= KB * (10 ** 3)

print(f'Current size is : {GB} GB, {MB} MB, {KB} KB, {size} bytes')
