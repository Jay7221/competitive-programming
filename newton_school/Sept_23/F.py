import math

MAX = 10**6 + 7
primes = []

def pre():
    global primes
    is_prime = [True] * MAX
    for p in range(2, MAX):
        if is_prime[p]:
            primes.append(p)
            for j in range(2, MAX):
                if j * p < MAX:
                    is_prime[j * p] = False
                else:
                    break

def solve():
    m = int(input())
    a = list(map(int, input().split()))
    freq = {}
    
    for elem in a:
        for p in primes:
            while elem % p == 0:
                elem //= p
                freq[p] = freq.get(p, 0) + 1

        l = int(math.sqrt(elem)) - 10
        l = max(l, 2)
        r = int(math.sqrt(elem)) + 10
        for p in range(l, r + 1):
            while elem % p == 0:
                elem //= p
                freq[p] = freq.get(p, 0) + 1

        if elem > 1:
            freq[elem] = freq.get(elem, 0) + 1

    k_max = 0
    no_primes = 0

    for p, k in freq.items():
        if k > k_max:
            k_max = k
            no_primes = 0
        if k == k_max:
            no_primes += 1

    ans = 1
    while no_primes > 0:
        ans <<= 1
        no_primes -= 1
    ans -= 1

    if k_max == 0:
        ans = -1

    print(k_max)
    print(ans)

if __name__ == "__main__":
    pre()
    solve()

