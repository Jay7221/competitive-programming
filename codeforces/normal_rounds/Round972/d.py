import itertools
t = 100
print(t)
for i in range(t):
    n = 5000
    ps = [2,3,5,7,11,13,17,19,23]
    prod = 1
    for i in ps:
        prod*=i

    a = [prod]*n
    b = [prod]*n
    l = len(ps)
    at=1
    for num in range(len(ps)+1):
        for i in itertools.combinations(ps,num):
            myp=1
            for j in i:
                myp*=j
            b[at*5]=myp
            at+=1
    print(n)
    print(*a)
    print(*b)
