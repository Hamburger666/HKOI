N = int(input())
p = [True] * (N+1)
n = 2
while n <= N:
    print(n)
    for m in range(n*n, N+1, n):
        p[m] = False
    n += 1
    while n <= N and not p[n]:
        n += 1
