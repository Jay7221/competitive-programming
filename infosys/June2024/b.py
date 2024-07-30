import sys

def allMEX(N, A):
    mex = 0
    for i in range(N):
        if A[i] > i:
            break
        mex = i + 1

    return [i for i in range(mex + 1)]

def main():
    N = int(sys.stdin.readline().strip())
    A = []
    for _ in range(N):
        A.append(int(sys.stdin.readline().strip()))

    result = allMEX(N, A)
    for j in range(len(result)):
        print(result[j])


main()
