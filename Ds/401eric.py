import math

n = int(input())
primes = []
i = 2

for m in range(2, n + 1):
    primes.append(m)

while i <= n:
    for j in range(i**2, n + 1, i):
        if j in primes:
            primes.remove(j)
    i += 1
    while i not in primes and i <= n:
        i += 1

for prime in primes:
    print(prime)