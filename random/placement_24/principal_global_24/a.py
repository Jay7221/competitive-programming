n = int(input())
arr = input().split()

turn = True

arr = [str(num) for num in arr]

while len(arr) > 1:
    if not turn:
        arr = [int(num) for num in arr]
    n = len(arr)
    arr2 = []
    for i in range(n):
        if i % 2 == 0:
            if i + 1 < n:
                arr2.append(arr[i] + arr[i + 1])
            else:
                arr2.append(arr[i])
    arr = arr2
    if not turn:
        arr = [str(num) for num in arr]
    turn = not turn

print(arr[0])
